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
//    QSqlQuery qry(db);
//    if(qry.exec("SELECT * FROM overall_performance"))
//    {
//        while(qry.next())
//        {
//            qDebug() << "Team: " << qry.value(0).toString() << "\t\tpts: " << qry.value(1).toString();
//        }
//    }
//    else
//    {
//        qDebug() << "Error: " << db.lastError();
//    }
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
