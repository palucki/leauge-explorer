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
}

void MainWindow::disconnectFromDatabase()
{
    databaseHandler->disconnectFromDatabase();
    updateConnectedIndicator(databaseHandler->getConnectionStatus());
}

void MainWindow::showLeaugeTable()
{
    databaseHandler->setResultTable(ui->resultTable);
    executeQuery();
}

void MainWindow::updateConnectedIndicator(bool state)
{
    ui->connectionIndicator->setChecked(state);
    if(state)
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: green }");
    }
    else
    {
        ui->connectionIndicator->setStyleSheet("QCheckBox::indicator { background-color: red }");
    }

}

void MainWindow::executeQuery()
{
    databaseHandler->executeQuery(ui->queryEditor->toPlainText());
}
