#include "MainWindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect signals and slots
    connect(ui->connectButton, SIGNAL(clicked()),this, SLOT(connectToDatabase()));
    connect(ui->disconnectButton, SIGNAL(clicked()),this, SLOT(disconnectFromDatabase()));
    connect(ui->showLeaugeTableButton, SIGNAL(clicked()),this, SLOT(showLeaugeTable()));
    connect(ui->executeQueryButton, SIGNAL(clicked()),this, SLOT(executeQueryFromEditor()));
    connect(ui->showSelectedButton, SIGNAL(clicked()),this, SLOT(showSelectedTable()));
    connect(ui->exitButton, SIGNAL(clicked()),this, SLOT(close()));
}

void MainWindow::setDatabaseHandler(DatabaseHandler* dbh)
{
    databaseHandler = dbh;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectToDatabase()
{
    databaseHandler->connectToDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());
    databaseHandler->setResultTable(ui->resultTable);
    databaseHandler->showAvailableTablesFromDatabaseIn(ui->allTables);
}

void MainWindow::disconnectFromDatabase()
{
    databaseHandler->disconnectFromDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());
    databaseHandler->clearAvailableTablesList(ui->allTables);
}

void MainWindow::showLeaugeTable()
{

}

void MainWindow::executeQueryFromEditor()
{
    databaseHandler->executeQuery(ui->queryEditor->toPlainText());
}

void MainWindow::showSelectedTable()
{
    if(ui->allTables->currentItem())
    {
        QString selectedTable = ui->allTables->currentItem()->text();
        databaseHandler->showTableInResults(selectedTable);
        qDebug() << "selected table: " << selectedTable;
    }
}

void MainWindow::updateConnectedIndicator(bool state)
{
    ui->connectionIndicator->setChecked(state);
    if(state)
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: green }");
        ui->showSelectedButton->setEnabled(true);
    }
    else
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: red }");
        ui->showSelectedButton->setEnabled(false);
    }

}

void MainWindow::on_allTables_itemDoubleClicked(QListWidgetItem *item)
{
    showSelectedTable();
}
