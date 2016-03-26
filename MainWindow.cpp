#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "simplesearch.h"

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), inEditingMode(false)
{
    ui->setupUi(this);
    ui->advancedOptions->setEnabled(false);
    newRecordWindow = new AddRecordHelper(this);
    userIdentity = "";
    connectAllSignals();
    on_searchTypeField_currentTextChanged(ui->searchTypeField->currentText());
}

void MainWindow::setDatabaseHandler(DatabaseHandler* dbh)
{
    databaseHandler = dbh;
    newRecordWindow->setDatabaseHandler(databaseHandler);
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
    qDebug() << "Edition mode: " << state;
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

//    databaseHandler->showAvailableTablesFromDatabaseIn(ui->availableTablesInSearch);
    setConnectionButtonsAfterConnectState();

    //setEditingButtonsState(false);
}

void MainWindow::disconnectFromDatabase()
{
    databaseHandler->disconnectFromDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());

    setConnectionButtonsInitialState();

    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    cleanupEnvironment();\
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

void MainWindow::setConnectionButtonsInitialState()
{
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->editModeButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->addRecordButton->setEnabled(false);
    ui->saveButton->setEnabled(false);
}

void MainWindow::cleanupEnvironment()
{
//    databaseHandler->clearAvailableTablesList(ui->allTablesasdasd);
//    databaseHandler->clearAvailableTablesList(ui->availableTablesInSearch);
    ui->allTablesasdasd->clear();
//    ui->availableTablesInSearch->clear();
    ui->columnForSearch->clear();
    for(int i = 0; i < ui->resultTable->columnCount(); i++)
        ui->resultTable->horizontalHeaderItem(i)->setText("");

    ui->resultTable->setColumnCount(0);
    ui->resultTable->setRowCount(0);
    ui->resultTable->clearContents();
}

void MainWindow::executeQueryFromEditor()
{
    databaseHandler->executeQuery(ui->queryEditor->toPlainText());
}

void MainWindow::showTableFrom(QListWidgetItem *item)
{
//    setConnectionButtonsAfterConnectState();
    inEditingMode = false;
    ui->saveButton->setEnabled(false);

    QString selectedTable = item->text();
    qDebug() << "selected table: " << selectedTable;
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

//void MainWindow::on_allTables_itemDoubleClicked(QListWidgetItem *item)
//{
//    showTableFrom(item);
//}

//void MainWindow::showSelectedFromButton()
//{
//    showTableFrom(ui->allTables->currentItem());
//}


void MainWindow::editSelectedTable()
{
    ui->resultTable->setEditTriggers(QAbstractItemView::DoubleClicked);

    ui->editModeButton->setEnabled(false);
    setEditingButtonsState(true);
}



void MainWindow::deletebuttonClicked()
{
    qDebug() << "Remove";

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
//    showTableFrom(ui->allTables->currentItem()); //update table
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
            qDebug() << "Correct password";
            qDebug() << "Welcome " << userIdentity;
            ui->usernameLineEdit->setEnabled(false);
            ui->passwordLineEdit->setEnabled(false);
            ui->signInButton->setText("Sign out");
        }
        else
            qDebug() << "Username or password incorrect";
    }
    else
    {
        userIdentity = "";
        ui->usernameLineEdit->setEnabled(true);
        ui->passwordLineEdit->setEnabled(true);
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
        ui->advancedOptions->setEnabled(true);
    }
    else
    {
        ui->advancedOptions->setEnabled(false);
    }
}

void MainWindow::on_searchButton_clicked()
{
    SearchType* searchType;
    QString searchTypeText = ui->searchTypeField->currentText();
    QStringList arguments;

    if(searchTypeText == "simple")
    {
        qDebug() << "Proste";
        searchType = new SimpleSearch(databaseHandler);
        arguments.push_back(ui->searchLineEdit->text());
        arguments.push_back(ui->allTablesasdasd->currentText());
        arguments.push_back(ui->columnForSearch->currentText());
    }

    else if(searchTypeText == "mathematical")
    {
        qDebug() << "Matematyczne";

    }
    else if(searchTypeText == "logical")
    {
        qDebug() << "Logiczne";
    }
    else
        qDebug() << "Unknown search type!";

    std::vector<FoundRecord> foundRecords = searchType->processQuery(arguments);

    showOnlyFoundRecordsInResultTable(foundRecords);
}

void MainWindow::on_allTablesasdasd_currentTextChanged(const QString &arg1)
{
    if(arg1 != "")
    {
        QListWidgetItem tempItem(arg1);
        showTableFrom(&tempItem);
        if(userIdentity != "")
            ui->editModeButton->setEnabled(true);

        ui->columnForSearch->clear();
        ui->columnForSearch->addItem("any column");

        QStringList columnNames = databaseHandler->getColumnNamesForTable(arg1);
        for(int i = 0; i < columnNames.size(); i++)
        {
            ui->columnForSearch->addItem(columnNames[i]);
        }
    }
}

void MainWindow::on_searchTypeField_currentTextChanged(const QString &arg1)
{
    if(arg1 == "simple")
    {
        ui->searchOptionBox->clear();
        ui->searchOptionBox->setEnabled(false);
        ui->searchLineEdit_2->clear();
        ui->searchLineEdit_2->setEnabled(false);
        ui->searchLineEdit_2->setPlaceholderText("");
    }
    else if(arg1 == "logical")
    {
        ui->searchOptionBox->clear();
        ui->searchOptionBox->setEnabled(true);
        ui->searchOptionBox->addItem("OR");
        ui->searchOptionBox->addItem("AND");

        ui->searchLineEdit_2->clear();
        ui->searchLineEdit_2->setEnabled(true);
        ui->searchLineEdit_2->setPlaceholderText("condition2");
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
        ui->searchLineEdit_2->clear();
        ui->searchLineEdit_2->setEnabled(true);
        ui->searchLineEdit_2->setPlaceholderText("constant");
    }
}
