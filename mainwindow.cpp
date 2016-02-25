#include "mainwindow.h"
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

    //Setup Database
    QString connectionName = "myDB";
    QString connectionTemplate = "DRIVER={SQL Server Native Client 11.0};SERVER=%1;DATABASE=%2;UID=%3;PWD=;WSID=.;Trusted_connection=yes";
    QString serverName = "(localdb)\\MyInstance";
    QString dbName = "leauge";
    QString userName = "Piotrek\\Piotr";
    QString connectionString = connectionTemplate.arg(serverName).arg(dbName).arg(userName);

    db = QSqlDatabase::addDatabase("QODBC3", connectionName);
    db.setDatabaseName(connectionString);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectToDatabase()
{
    if(db.open())
    {
        qDebug() << "Opened";

    }
    else
    {
        qDebug() << "Could not open database with following credentials:";
        qDebug() << "User name: " << db.userName();
        qDebug() << "Database name: " << db.databaseName();
        qDebug() << db.lastError();
    }
}

void MainWindow::disconnectFromDatabase()
{
    if(db.isOpen())
    {
        qDebug() << "Closing";
        db.close();
    }
}

void MainWindow::showLeaugeTable()
{
    QSqlQuery qry(db);
    if(qry.exec("SELECT * FROM overall_performance"))
    {
        while(qry.next())
        {
            qDebug() << "Team: " << qry.value(0).toString() << "\t\tpts: " << qry.value(1).toString();
        }
    }
    else
    {
        qDebug() << "Error: " << db.lastError();
    }
}
