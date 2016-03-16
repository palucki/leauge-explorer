#include "MainWindow.h"
#include "ui_mainwindow.h"

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
    newRecordWindow = new AddRecordHelper(this);
    userIdentity = "";
    connectAllSignals();
}

void MainWindow::setDatabaseHandler(DatabaseHandler* dbh)
{
    databaseHandler = dbh;
    newRecordWindow->setDatabaseHandler(databaseHandler);
}

MainWindow::~MainWindow()
{
    cleanupEnvironment();
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
    databaseHandler->showAvailableTablesFromDatabaseIn(ui->allTables);

    setConnectionButtonsAfterConnectState();

    //setEditingButtonsState(false);
}

void MainWindow::disconnectFromDatabase()
{
    databaseHandler->disconnectFromDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());

    setConnectionButtonsInitialState();

    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    cleanupEnvironment();
}

void MainWindow::setConnectionButtonsAfterConnectState()
{
    inEditingMode = false;

    ui->connectButton->setEnabled(false);
    ui->disconnectButton->setEnabled(true);
    ui->editModeButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
    ui->addRecordButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
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
    databaseHandler->clearAvailableTablesList(ui->allTables);
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
    setConnectionButtonsAfterConnectState();


    if(!item) {
       item = ui->allTables->currentItem();
       qDebug() << "Allocated to item";
    }
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

void MainWindow::on_allTables_itemDoubleClicked(QListWidgetItem *item)
{
    showTableFrom(item);
}

void MainWindow::showSelectedFromButton()
{
    showTableFrom(ui->allTables->currentItem());
}


void MainWindow::editSelectedTable()
{
    ui->resultTable->setEditTriggers(QAbstractItemView::DoubleClicked);

    ui->editModeButton->setEnabled(false);
    setEditingButtonsState(true);
}



void MainWindow::deletebuttonClicked()
{
        qDebug() << "Remove";


        databaseHandler->removeCurrentRow();

        ui->resultTable->removeRow(ui->resultTable->currentRow());
        ui->resultTable->setCurrentCell(ui->resultTable->currentRow(), ui->resultTable->currentColumn());
}

void MainWindow::addRecordButtonClicked()
{
    if(ui->allTables->currentRow() != -1)
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
        newRecordWindow->prepareIdColumn(ui->allTables->currentItem()->text());


        //add rows
        newRecordWindow->show();
    }
}

void MainWindow::savebuttonClicked()
{
    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->editModeButton->setEnabled(true);

    databaseHandler->saveChangesToDatabase();
    showTableFrom(ui->allTables->currentItem()); //update table
}

void MainWindow::on_resultTable_itemChanged(QTableWidgetItem *item)
{
    if(inEditingMode)
    {
        databaseHandler->addUpdateQueryToQueriesList(item->row());
    }
}

void MainWindow::on_signInButton_clicked()
{
    //add some hash function in the future

    LoginHelper loginHelper(databaseHandler);

    std::map<std::string, std::string> usersCredentials;
    usersCredentials["user"] = "user";
    usersCredentials["admin"] = "admin";
    usersCredentials["default"] = "1234";

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

}
