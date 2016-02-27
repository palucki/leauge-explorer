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

void DatabaseHandler::prepareColumns(QSqlQuery qry)
{
    int numberOfCols = qry.record().count();
    resultTable->setColumnCount(numberOfCols);

    QStringList headerList;
    for(int i = 0; i < numberOfCols; i++)
    {
        headerList << qry.record().fieldName(i);
        qDebug() << qry.record().fieldName(i);
    }
    resultTable->setHorizontalHeaderLabels(headerList);
}

void DatabaseHandler::fillTableWithQueryData(QSqlQuery qry)
{
    for(int i = 0; qry.next(); i++)
    {
        if(resultTable->rowCount() <= i)
            resultTable->insertRow(i);

        for(int j = 0; j < resultTable->columnCount(); j++)
        {
            if(0 == resultTable->item(i,j))
            {
                resultTable->setItem(i,j,new QTableWidgetItem);
                qDebug() << "Allocation of new items in table";
            }
            resultTable->item(i,j)->setText(qry.value(j).toString());
        }
    }
}

void DatabaseHandler::executeQuery(const QString query)
{
    QSqlQuery qry(db);
    if(qry.exec(query))
    {
        prepareColumns(qry);
        fillTableWithQueryData(qry);
    }
    else
    {
        qDebug() << "Error: " << db.lastError();
    }
}

void DatabaseHandler::setResultTable(QTableWidget *resTab)
{
    resultTable = resTab;
}
