#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler()
{
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

void DatabaseHandler::connectToDatabase()
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

void DatabaseHandler::disconnectFromDatabase()
{
    if(db.isOpen())
    {
        qDebug() << "Closing";
        db.close();
    }
}
