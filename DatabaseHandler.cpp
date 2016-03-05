#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler()
{
    if(!db.isValid())
        setDatabase();
}

void DatabaseHandler::setDatabase()
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

DatabaseHandler::~DatabaseHandler()
{
    QSqlDatabase::removeDatabase(db.connectionName());
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

void DatabaseHandler::prepareColumns(const QSqlQuery qry)
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

            if(j == 0)
                resultTable->item(i,j)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
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
    qry.finish();
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
    qry.finish();
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
    qry.finish();
}

void DatabaseHandler::updateDatabase(int row, int column)
{
    qDebug() << "Cell: " << row << " " << column << " changed";
}

void DatabaseHandler::saveChangesToDatabase()
{
    //add updating database here:

//    QSqlQuery qry(db);
//    QString query = "SELECT COUNT(*) FROM ";
//    query.append(currentTable);

//    qDebug() << query;
//    if(qry.exec(query))
//       qDebug() << "Success";
//    else
//        logDbError();

//    qry.next();

//    auto rowsToBeAdde = resultTable->rowCount() - qry.value(0).toInt();
//    qDebug() << "Rows to be added: " << rowsToBeAdde;

//    for(auto processedRow = qry.value(0).toInt(); processedRow < resultTable->rowCount(); processedRow++)
//    {
        auto processedRow = resultTable->currentRow();
        QString query;
        query = "INSERT INTO ";
        query.append(currentTable);
        query.append(" VALUES (");

        for(int i = 1; i < resultTable->columnCount(); i++) //don't insert 1st column, its ID
        {
            if(resultTable->item(processedRow, i)) {
                QString value = resultTable->item(processedRow, i)->text();
                if(value.at(0).isLetter())
                {
                    value.prepend("'");
                    value.append("'");
                }
                query.append(value);
            }
            else
                query.append(" ");
            query.append(",");
        }
        query.remove(query.length()-1, 1); //remove last comma
        query.append(")");
        qDebug() << "zapytanie: " << query;

        QSqlQuery qry(db);
        if(qry.exec(query))
            qDebug() << "Dodano " << query;
        else
            logDbError();
//    }
        qry.finish();
}

int DatabaseHandler::getNextId(const QString fromTableName)
{
    int nextId = -1;
    QString query = "SELECT MAX(id) FROM ";
    query.append(fromTableName);
    qDebug() << query;

    QSqlQuery qry(db);

    if(qry.exec(query)){
        qry.next();
        nextId = qry.value(0).toInt() + 1;
    }
    else
        logDbError();

    return nextId;
}


void DatabaseHandler::insertNewRow(QStringList fields)
{
    QString query;
    query = "INSERT INTO ";
    query.append(currentTable);
    query.append(" VALUES (");

    for(int i = 0; i < fields.count(); i++) //don't insert 1st column, its ID
    {

            QString value = fields.at(i);
            if(value.at(0).isLetter() || value == "")
            {
                value.prepend("'");
                value.append("'");
            }
            query.append(value);


        query.append(",");
    }
    query.remove(query.length()-1, 1); //remove last comma
    query.append(")");

    qDebug() << "zapytanie: " << query;

    QSqlQuery qry(db);
    if(qry.exec(query))
        qDebug() << "Dodano " << query;
    else
        logDbError();

    qry.finish();
}

void DatabaseHandler::refreshTable()
{
    showTableInResults(currentTable);
}
