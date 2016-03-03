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
    int rowCount = 0;
    for(int i = 0; qry.next(); i++, rowCount++)
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

    resultTable->setRowCount(rowCount);
    qDebug() <<"Row count set to: " << rowCount;
}

void DatabaseHandler::logDbError()
{
    qDebug() << "Error: " << db.lastError();
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
        logDbError();
}

void DatabaseHandler::setResultTable(QTableWidget *resTab)
{
    resultTable = resTab;
}

void DatabaseHandler::showAvailableTablesFromDatabaseIn(QListWidget *list)
{
    QSqlQuery qry(db);
    if(qry.exec("SELECT * FROM information_schema.tables"))
    {
        while(qry.next())
        {
            list->addItem(new QListWidgetItem(qry.record().value(2).toString()));
        }
    }
    else
        logDbError();
}

void DatabaseHandler::clearAvailableTablesList(QListWidget *list)
{
    list->clear();
}

void DatabaseHandler::showTableInResults(const QString tableName)
{
    currentTable = tableName;
    QSqlQuery qry(db);
    QString query = "SELECT * FROM ";

    query.append(tableName);
    if(tableName == "overall_performance") {
        qDebug() << "Sort by points";
        query.append(" ORDER BY points DESC");
    }

    if(qry.exec(query))
    {
        resultTable->clearContents();
        prepareColumns(qry);
        fillTableWithQueryData(qry);
    }
    else
        logDbError();

    qDebug() << "Current table is " << currentTable;
}

void DatabaseHandler::updateDatabase(int row, int column)
{
    qDebug() << "Cell: " << row << " " << column << " changed";
}

void DatabaseHandler::saveRowToDatabase()
{
    QString query = "INSERT INTO ";
    query.append(currentTable);
    query.append(" VALUES (");

    bool willBeInserted = true;
    for(int i = 0; i < resultTable->columnCount(); i++)
    {
        if(resultTable->item(resultTable->currentRow(), i))
        {
            query.append(resultTable->item(resultTable->currentRow(), i)->text());
            query.append(",");
        }
        else
        {
            willBeInserted = false;
            qDebug() << "Wyskakujace okienko ze pola (poza id) są puste";
        }
    }
    query.append(")");
    qDebug() << query;

    if(willBeInserted)
        qDebug() << "Poprawnie wypelnione, bedzie dodane";
    //qry.exec(query);
}
