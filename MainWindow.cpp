#include "MainWindow.h"
#include "ui_mainwindow.h"


void MainWindow::connectAllSignals()
{
    connect(ui->connectButton, SIGNAL(clicked()),this, SLOT(connectToDatabase()));
    connect(ui->disconnectButton, SIGNAL(clicked()),this, SLOT(disconnectFromDatabase()));
    connect(ui->showLeaugeTableButton, SIGNAL(clicked()),this, SLOT(showLeaugeTable()));
    connect(ui->executeQueryButton, SIGNAL(clicked()),this, SLOT(executeQueryFromEditor()));
    connect(ui->showSelectedButton, SIGNAL(clicked()),this, SLOT(showSelectedFromButton()));
    connect(ui->editModeButton, SIGNAL(clicked()),this, SLOT(editSelectedTable()));
    connect(ui->saveButton, SIGNAL(clicked()),this, SLOT(savebuttonClicked()));
    connect(ui->deleteButton, SIGNAL(clicked()),this, SLOT(deletebuttonClicked()));
    connect(ui->addRecordButton, SIGNAL(clicked()),this, SLOT(addrecordbuttonClicked()));
    connect(ui->exitButton, SIGNAL(clicked()),this, SLOT(close()));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectAllSignals();
}

void MainWindow::setDatabaseHandler(DatabaseHandler* dbh)
{
    databaseHandler = dbh;
}

MainWindow::~MainWindow()
{
    cleanupEnvironment();
    delete ui;
}


void MainWindow::connectToDatabase()
{
    databaseHandler->connectToDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());
    databaseHandler->setResultTable(ui->resultTable);
    databaseHandler->showAvailableTablesFromDatabaseIn(ui->allTables);
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

void MainWindow::disconnectFromDatabase()
{
    databaseHandler->disconnectFromDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());
    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    cleanupEnvironment();
}

void MainWindow::showLeaugeTable()
{

}

void MainWindow::executeQueryFromEditor()
{
    databaseHandler->executeQuery(ui->queryEditor->toPlainText());
}

void MainWindow::showTableFrom(QListWidgetItem *item)
{
    if(!item) {
       item = ui->allTables->currentItem();
       qDebug() << "Allocated to item";
    }
    QString selectedTable = item->text();
    databaseHandler->showTableInResults(selectedTable);
    qDebug() << "selected table: " << selectedTable;

}

void MainWindow::showSelectedFromButton()
{
    showTableFrom(ui->allTables->currentItem());
}

void MainWindow::updateConnectedIndicator(bool state)
{
    ui->connectionIndicator->setChecked(state);
    if(state)
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: green }");
        ui->showSelectedButton->setEnabled(true);
        ui->editModeButton->setEnabled(true);
        //ui->saveButton->setEnabled(true);
        //ui->deleteButton->setEnabled(true);
        //TO DO: add every button here and extract function at the end
    }
    else
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: red }");
        ui->showSelectedButton->setEnabled(false);
        ui->editModeButton->setEnabled(false);
        //ui->saveButton->setEnabled(false);
        //ui->deleteButton->setEnabled(false);
        //TO DO: add every button here
    }
}

void MainWindow::on_allTables_itemDoubleClicked(QListWidgetItem *item)
{
    showTableFrom(item);
}

void MainWindow::editSelectedTable()
{
    //TO DO: add sth to mark table as "being edited"
    //
    ui->resultTable->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->saveButton->setEnabled(true);
    ui->deleteButton->setEnabled(true);
    ui->addRecordButton->setEnabled(true);
    ui->editModeButton->setEnabled(false);
}

void MainWindow::savebuttonClicked()
{
    ui->resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->saveButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->addRecordButton->setEnabled(false);
    ui->editModeButton->setEnabled(true);
}

void MainWindow::deletebuttonClicked()
{
    ui->resultTable->removeRow(ui->resultTable->currentRow());
}

void MainWindow::addrecordbuttonClicked()
{
    ui->resultTable->insertRow(ui->resultTable->rowCount());
}


void MainWindow::on_resultTable_cellChanged(int row, int column)
{
    databaseHandler->updateDatabase(row, column);
}
