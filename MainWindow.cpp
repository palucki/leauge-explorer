#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "simplesearch.h"
#include "mathsearch.h"
#include "logicalsearch.h"
#include "plotter.h"

#include "DatabaseHandler.h"
#include "AddRecordHelper.h"
#include "loginhelper.h"

#include "searchtype.h"
#include "logger.h"
#include "plotter.h"

#include "tableexporter.h"


void MainWindow::connectAllSignals()
{
    connect(ui->connectButton, SIGNAL(clicked()),this, SLOT(connectToDatabase()));
    connect(ui->disconnectButton, SIGNAL(clicked()),this, SLOT(disconnectFromDatabase()));
    connect(ui->executeQueryButton, SIGNAL(clicked()),this, SLOT(executeQueryFromEditor()));
    connect(ui->editModeButton, SIGNAL(clicked()),this, SLOT(editSelectedTable()));
    connect(ui->saveButton, SIGNAL(clicked()),this, SLOT(savebuttonClicked()));
    connect(ui->deleteButton, SIGNAL(clicked()),this, SLOT(deletebuttonClicked()));
    connect(ui->addRecordButton, SIGNAL(clicked()),this, SLOT(addRecordButtonClicked()));
    connect(ui->exitButton, SIGNAL(clicked()),this, SLOT(close()));
}

void MainWindow::disableAdminButtons()
{
    ui->queryEditor->setEnabled(false);
    ui->executeQueryButton->setEnabled(false);
}

void MainWindow::enableAdminButtons()
{
    ui->queryEditor->setEnabled(true);
    ui->executeQueryButton->setEnabled(true);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), inEditingMode(false)
{
    ui->setupUi(this);

    ui->exportTableButton->setEnabled(true);
    disableAdminButtons();
    newRecordWindow = new AddRecordHelper(this);
    userIdentity = "";
    connectAllSignals();
    Logger::getInstance().logQuery("Started application", __FILE__, __LINE__);
}

void MainWindow::setDatabaseHandler(DatabaseHandler* dbh)
{
    databaseHandler = dbh;
    newRecordWindow->setDatabaseHandler(databaseHandler);
    plotter.setDatabaseHandler(databaseHandler);
}

MainWindow::~MainWindow()
{
    cleanupEnvironment();
    databaseHandler->disconnectFromDatabase();
    delete newRecordWindow;
    delete ui;
}

void MainWindow::setEditingButtonsState(bool state)
{
    //qDebug() << "Edition mode: " << state;
    inEditingMode = state;
    ui->saveButton->setEnabled(state);
    ui->addRecordButton->setEnabled(state);
}

void MainWindow::connectToDatabase()
{
    databaseHandler->connectToDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());
    databaseHandler->setResultTable(ui->resultTable);
    databaseHandler->showAvailableTablesFromDatabaseIn(ui->allTablesasdasd);

    setConnectionButtonsAfterConnectState();
    Logger::getInstance().logQuery("Connected to database", __FILE__, __LINE__);
    on_searchTypeField_currentTextChanged(ui->searchTypeField->currentText());
}

void MainWindow::disconnectFromDatabase()
{
    databaseHandler->disconnectFromDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());

    setConnectionButtonsInitialState();

    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    cleanupEnvironment();\
    Logger::getInstance().logQuery("Disconnected from database", __FILE__, __LINE__);
}

void MainWindow::setConnectionButtonsInitialState()
{
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->editModeButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->addRecordButton->setEnabled(false);
    ui->saveButton->setEnabled(false);

    userIdentity = "";
    ui->passwordLineEdit->clear();
    ui->passwordLineEdit->setEnabled(false);
    ui->usernameLineEdit->clear();
    ui->usernameLineEdit->setEnabled(false);
    ui->signInButton->setEnabled(true);
    on_signInButton_clicked();
}

void MainWindow::setConnectionButtonsAfterConnectState()
{
    inEditingMode = false;

    ui->connectButton->setEnabled(false);
    ui->disconnectButton->setEnabled(true);
    ui->editModeButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->addRecordButton->setEnabled(false);
    ui->saveButton->setEnabled(false);

    ui->searchButton->setEnabled(true);
    ui->searchTypeField->setEnabled(true);

    ui->usernameLineEdit->clear();
    ui->usernameLineEdit->setEnabled(true);
    ui->passwordLineEdit->clear();
    ui->passwordLineEdit->setEnabled(true);
    ui->signInButton->setEnabled(true);

}

void MainWindow::disableEditingButtonsForUnknownUser()
{
    ui->editModeButton->setEnabled(false);
    ui->saveButton->setEnabled(false);
    ui->addRecordButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
}

void MainWindow::enableEditingButtonsForKnownUser()
{
    ui->editModeButton->setEnabled(true);
    ui->addRecordButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
}

void MainWindow::showOnlyFoundRecordsInResultTable(std::vector<FoundRecord> foundRecords)
{
    databaseHandler->showFoundRecordsInResultTable(foundRecords);
}



void MainWindow::cleanupEnvironment()
{
    ui->allTablesasdasd->clear();
    ui->columnForSearch->clear();
    for(int i = 0; i < ui->resultTable->columnCount(); i++)
        ui->resultTable->horizontalHeaderItem(i)->setText("");

    ui->resultTable->setColumnCount(0);
    ui->resultTable->setRowCount(0);
    ui->resultTable->clearContents();
    ui->chartButton->setEnabled(false);
}

void MainWindow::executeQueryFromEditor()
{
    databaseHandler->executeQuery(ui->queryEditor->toPlainText());
}

void MainWindow::showTableFrom(QListWidgetItem *item)
{
    inEditingMode = false;
    ui->saveButton->setEnabled(false);

    QString selectedTable = item->text();
    databaseHandler->showTableInResults(selectedTable);
}

void MainWindow::updateConnectedIndicator(bool state)
{
    if(state)
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: green }");
    }
    else
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: red }");
    }
}

void MainWindow::editSelectedTable()
{
    ui->resultTable->setEditTriggers(QAbstractItemView::DoubleClicked);

    ui->editModeButton->setEnabled(false);
    setEditingButtonsState(true);
}

void MainWindow::deletebuttonClicked()
{
    if(ui->resultTable->currentRow() != -1)
    {
        databaseHandler->removeCurrentRow();
        ui->resultTable->removeRow(ui->resultTable->currentRow());
        ui->resultTable->setCurrentCell(ui->resultTable->currentRow(), ui->resultTable->currentColumn());
    }
}

void MainWindow::addRecordButtonClicked()
{
    if(ui->allTablesasdasd->currentText() != "")
    {
        //clear contents
        newRecordWindow->clearTable();

        //update table headers
        QStringList headersList;
        for(int i = 0; i < ui->resultTable->columnCount(); i++)
        {
            headersList << ui->resultTable->horizontalHeaderItem(i)->text();
        }
        newRecordWindow->updateTableHeaders(ui->resultTable->columnCount(), headersList);
        newRecordWindow->prepareIdColumn(ui->allTablesasdasd->currentText());

        //add rows
        newRecordWindow->show();
    }
}

void MainWindow::savebuttonClicked()
{
    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->editModeButton->setEnabled(true);

    databaseHandler->saveChangesToDatabase();
    QListWidgetItem tempItem(ui->allTablesasdasd->currentText());
    showTableFrom(&tempItem); //update table
    ui->editModeButton->setEnabled(true);
}

void MainWindow::on_resultTable_itemChanged(QTableWidgetItem *item)
{
    if(inEditingMode)
    {
        databaseHandler->addUpdateQueryToQueriesList(item->row(), item->column());
    }
}

void MainWindow::on_signInButton_clicked()
{
    LoginHelper loginHelper(databaseHandler);

    std::string userName = ui->usernameLineEdit->text().toStdString();
    std::string password = ui->passwordLineEdit->text().toStdString();

    bool passwordCorrect = loginHelper.userOK(userName, password);

    if(userIdentity == "")
    {
        if(passwordCorrect)
        {
            userIdentity = QString::fromStdString(userName);
            //qDebug() << "Correct password";
            //qDebug() << "Welcome " << userIdentity;
            ui->usernameLineEdit->setEnabled(false);
            ui->passwordLineEdit->setEnabled(false);
            ui->signInButton->setText("Sign out");
        }
        else
            ui->signInButton->setText("Sign in");
            //qDebug() << "Username or password incorrect";
    }
    else
    {
        userIdentity = "";
        ui->usernameLineEdit->setEnabled(true);
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->setEnabled(true);
        ui->passwordLineEdit->clear();
        ui->signInButton->setText("Sign in");
    }

    if(userIdentity == "")
    {
        disableEditingButtonsForUnknownUser();
    }
    else
    {
        enableEditingButtonsForKnownUser();
    }

    if(userIdentity == "admin")
    {
        enableAdminButtons();
    }
    else
    {
        disableAdminButtons();
    }
}

void MainWindow::on_searchButton_clicked()
{
    SearchType* searchType;
    QString searchTypeText = ui->searchTypeField->currentText();
    QStringList arguments;

    if(searchTypeText == "simple")
    {
        //qDebug() << "Proste";
        searchType = new SimpleSearch(databaseHandler);
        arguments.push_back(ui->searchLineEdit->text());
        arguments.push_back(ui->allTablesasdasd->currentText());
        arguments.push_back(ui->columnForSearch->currentText());
    }

    else if(searchTypeText == "mathematical")
    {
        //qDebug() << "Matematyczne";
        searchType = new MathSearch(databaseHandler);
        arguments.push_back(ui->allTablesasdasd->currentText());
        arguments.push_back(ui->searchLineEdit->text());
        arguments.push_back(ui->searchOptionBox->currentText());
        arguments.push_back(ui->searchLineEdit_2->text());

    }
    else if(searchTypeText == "logical")
    {
        //qDebug() << "Logiczne";
        searchType = new LogicalSearch(databaseHandler);
        arguments.push_back(ui->allTablesasdasd->currentText());
        arguments.push_back(ui->columnForSearch->currentText());
        arguments.push_back(ui->searchLineEdit->text());
        arguments.push_back(ui->searchOptionBox->currentText());
        arguments.push_back(ui->searchLineEdit_2->text());

        //qDebug() << arguments;
    }
//    else
        //qDebug() << "Unknown search type!";

    std::vector<FoundRecord> foundRecords = searchType->processQuery(arguments);


    if(foundRecords.size() > 0)
        showOnlyFoundRecordsInResultTable(foundRecords);
    else
    {
        ui->resultTable->clearContents();
        ui->resultTable->setRowCount(0);
    }
}

void MainWindow::prepareColumnsForSearch(const QString &arg1)
{
    ui->columnForSearch->clear();
    ui->columnForSearch->addItem("any column");
    QStringList columnNames = databaseHandler->getColumnNamesForTable(arg1);
    for(int i = 0; i < columnNames.size(); i++)
    {
        ui->columnForSearch->addItem(columnNames[i]);
    }
}

void MainWindow::on_allTablesasdasd_currentTextChanged(const QString &arg1)
{
    if(arg1 != "")
    {
        QListWidgetItem tempItem(arg1);
        showTableFrom(&tempItem);
        if(userIdentity != "")
            ui->editModeButton->setEnabled(true);

        prepareColumnsForSearch(arg1);
        enableChartButtonIfRequired();
    }
}

void MainWindow::enableChartButtonIfRequired()
{
    if(ui->allTablesasdasd->currentText() == "overall_attendance")
        ui->chartButton->setEnabled(true);
    else
        ui->chartButton->setEnabled(false);
}



void MainWindow::on_searchTypeField_currentTextChanged(const QString &arg1)
{
    if(arg1 == "simple")
    {
        prepareColumnsForSearch(ui->allTablesasdasd->currentText());
        ui->columnForSearch->setEnabled(true);
        ui->searchOptionBox->clear();
        ui->searchOptionBox->setEnabled(false);
        ui->searchLineEdit->clear();
        ui->searchLineEdit->setEnabled(true);
        ui->searchLineEdit->setPlaceholderText("(eg. Kraków)");
        ui->searchLineEdit_2->clear();
        ui->searchLineEdit_2->setEnabled(false);
        ui->searchLineEdit_2->setPlaceholderText("");
    }
    else if(arg1 == "logical")
    {
        prepareColumnsForSearch(ui->allTablesasdasd->currentText());
        ui->columnForSearch->setEnabled(true);
        ui->searchOptionBox->clear();
        ui->searchOptionBox->setEnabled(true);
        ui->searchOptionBox->addItem("OR");
//        ui->searchOptionBox->addItem("AND");
        ui->searchLineEdit->clear();
        ui->searchLineEdit->setEnabled(true);
        ui->searchLineEdit->setPlaceholderText("text1");
        ui->searchLineEdit_2->clear();
        ui->searchLineEdit_2->setEnabled(true);
        ui->searchLineEdit_2->setPlaceholderText("text2");
    }
    else if(arg1 == "mathematical")
    {
        ui->searchOptionBox->clear();
        ui->searchOptionBox->setEnabled(true);
        ui->searchOptionBox->addItem("=");
        ui->searchOptionBox->addItem("!=");
        ui->searchOptionBox->addItem(">");
        ui->searchOptionBox->addItem("<");
        ui->searchOptionBox->addItem(">=");
        ui->searchOptionBox->addItem("<=");
        ui->searchLineEdit->clear();
        ui->searchLineEdit->setEnabled(true);
        ui->searchLineEdit->setPlaceholderText("column name");
        ui->searchLineEdit_2->clear();
        ui->searchLineEdit_2->setEnabled(true);
        ui->searchLineEdit_2->setPlaceholderText("constant");
        ui->columnForSearch->clear();
        ui->columnForSearch->setEnabled(false);
    }
}

void MainWindow::on_chartButton_clicked()
{
    plotter.show();
    plotter.showOverallAttendance();
}

void MainWindow::on_exportTableButton_clicked()
{
    qDebug() << "export clicked";
    TableExporter exporter;
    exporter.saveTableInCsv("table.csv", ui->resultTable);
}
