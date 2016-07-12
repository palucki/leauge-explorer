#include "DatabaseHandler.h"
#include "logger.h"
#include "foundrecord.h"
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
    Logger::getInstance().log("Connection string:", __FILE__, __LINE__);
    Logger::getInstance().log(connectionString, __FILE__, __LINE__);
}

DatabaseHandler::~DatabaseHandler()
{
//    QSqlDatabase::removeDatabase(db.connectionName());
}

void DatabaseHandler::connectToDatabase()
{
    if(db.open())
    {
        //qDebug() << "Opened";
    }
    else
    {
        //qDebug() << "Could not open database with following credentials:";
        //qDebug() << "User name: " << db.userName();
        //qDebug() << "Database name: " << db.databaseName();
        //qDebug() << db.lastError();
    }
}

void DatabaseHandler::disconnectFromDatabase()
{
    if(db.isOpen())
    {
        //qDebug() << "Closing";
        db.close();
    }
}



void DatabaseHandler::prepareColumns(const QSqlQuery qry)
{
    int numberOfCols = qry.record().count();
    resultTable->setColumnCount(numberOfCols);

    QStringList headerList = getColumnNamesForTable(currentTable);
    resultTable->setHorizontalHeaderLabels(headerList);
}


QStringList DatabaseHandler::getColumnNamesForTable(QString tableName)
{
    QStringList headerList;
    QSqlQuery qry(db);

    QString query = QString("SELECT TOP 0 * FROM %1").arg(tableName);
    Logger::getInstance().log(query, __FILE__, __LINE__);

    if(qry.exec(query))
    {
        int numberOfCols = qry.record().count();
        for(int i = 0; i < numberOfCols; i++)
        {
            headerList << qry.record().fieldName(i);
            //qDebug() << qry.record().fieldName(i);
        }
    }
    else
        logDbError();
    qry.finish();

    return headerList;
}

void DatabaseHandler::showQueryResults(QSqlQuery qry)
{
    resultTable->clearContents();
    prepareColumns(qry);
    fillTableWithQueryData(qry);
}

void DatabaseHandler::executeGivenQueryAndShowResults(QSqlQuery qry, QString query)
{
    Logger::getInstance().log(query, __FILE__, __LINE__);
    if(qry.exec(query))
    {
        showQueryResults(qry);
    }
    else
        logDbError();

    qry.finish();
}

void DatabaseHandler::showFoundRecordsInResultTable(std::vector<FoundRecord> fr)
{
    QSqlQuery qSqlQry(db);

    QString queryText = QString("SELECT * FROM %1 WHERE ").arg(fr[0].getTableName());

    for(int i = 0; i < fr.size(); i++)
    {
        queryText.append("id='");
        queryText.append(QString::number(fr[i].getRow()));
        queryText.append("' OR ");
    }

    queryText.remove(queryText.length()-3, 3); // remove last "OR "
    //qDebug() << queryText;

    Logger::getInstance().log(queryText, __FILE__, __LINE__);
    executeGivenQueryAndShowResults(qSqlQry, queryText);
}

std::vector<std::pair<double, double> > DatabaseHandler::getOverallAttendance()
{
    std::vector<std::pair<double, double> > overallAttendance;
    QSqlQuery qSqlQry(db);

    QString queryText = QString("SELECT * FROM overall_attendance ");
    //qDebug() << queryText;

    if(qSqlQry.exec(queryText))
    {
        while(qSqlQry.next())
        {
            double weekLabel = qSqlQry.record().value(1).toDouble();
            double attendance = qSqlQry.record().value(2).toDouble();
            overallAttendance.push_back(std::make_pair(weekLabel, attendance));
        }
    }
    else
        logDbError();

    Logger::getInstance().log(queryText, __FILE__, __LINE__);
    return overallAttendance;
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
//                //qDebug() << "Allocation of new items in table";
            }
            resultTable->item(i,j)->setText(qry.value(j).toString());

            if(j == 0)
                resultTable->item(i,j)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        }
    }
    resultTable->setRowCount(rowCount);
    //qDebug() <<"Row count set to: " << rowCount;
}

void DatabaseHandler::logDbError()
{
    //qDebug() << "Error: " << db.lastError();
}

void DatabaseHandler::executeQuery(const QString queryText)
{
    QSqlQuery qSqlQry(db);
    executeGivenQueryAndShowResults(qSqlQry, queryText);
}

void DatabaseHandler::setResultTable(QTableWidget *resTab)
{
    resultTable = resTab;
}

void DatabaseHandler::showAvailableTablesFromDatabaseIn(QComboBox* box)
{
    QSqlQuery qry(db);
    QString queryText = "SELECT * FROM information_schema.tables";
    Logger::getInstance().log(queryText, __FILE__, __LINE__);
    if(qry.exec(queryText))
    {
        while(qry.next())
        {
            box->addItem(qry.record().value(2).toString());
        }
    }
    else
        logDbError();
    qry.finish();
}

void DatabaseHandler::clearAvailableTablesList(QComboBox* box)
{
    box->clear();
}

void DatabaseHandler::showTableInResults(const QString tableName)
{
    currentTable = tableName;

    //qDebug() << currentTable;

    QSqlQuery qSqlQry(db);
    QString queryText = "SELECT * FROM ";

    queryText.append(tableName);
    if(tableName == "overall_performance") {
        //qDebug() << "Sort by points";
        queryText.append(" ORDER BY points DESC");
    }

    Logger::getInstance().log(queryText, __FILE__, __LINE__);
    executeGivenQueryAndShowResults(qSqlQry, queryText);
}

void DatabaseHandler::addUpdateQueryToQueriesList(int row, int column)
{
    //qDebug() << "Row: " << row << " " " changed";
//    SYNTAX:
//    UPDATE table_name
//    SET column1=value1,column2=value2,...
//    WHERE some_column=some_value;


    QString query = "UPDATE ";
    query.append(currentTable);
    query.append(" ");
    query.append("SET ");

    query.append(resultTable->horizontalHeaderItem(column)->text());
    query.append("='");
    query.append(resultTable->item(row,column)->text());
    query.append("'");

    query.append(" WHERE ");
    query.append(resultTable->horizontalHeaderItem(0)->text());
    query.append("='");
    query.append(resultTable->item(row,0)->text());
    query.append("'");
    query.append(";");

    //qDebug() << "zapytanie: " << query;
    queriesList.push_back(query);
}

void DatabaseHandler::saveChangesToDatabase()
{
    for(auto it = queriesList.begin(); it != queriesList.end(); it++)
    {
        //qDebug() << *it;
        QString query = *it;

        Logger::getInstance().log(query, __FILE__, __LINE__);

        QSqlQuery qry(db);
        if(qry.exec(query)) ;
            //qDebug() << "Dodano " << query;
        else
            logDbError();
        qry.finish();
    }

    queriesList.clear();
}

int DatabaseHandler::getNextId(const QString fromTableName)
{
    int nextId = -1;
    QString query = "SELECT MAX(id) FROM ";
    query.append(fromTableName);
    //qDebug() << query;
    Logger::getInstance().log(query, __FILE__, __LINE__);


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

    //qDebug() << "zapytanie: " << query;
    Logger::getInstance().log(query, __FILE__, __LINE__);
    QSqlQuery qry(db);
    if(qry.exec(query)) ;
        //qDebug() << "Dodano " << query;
    else
        logDbError();

    qry.finish();
}

void DatabaseHandler::refreshTable()
{
    showTableInResults(currentTable);
}

void DatabaseHandler::removeCurrentRow()
{
    int currentRow = resultTable->currentRow();
    QString currentId = resultTable->item(currentRow, 0)->text();

    QString query = "DELETE FROM ";
    query.append(currentTable);
    query.append(" WHERE id=");
    query.append(currentId);

    Logger::getInstance().log(query, __FILE__, __LINE__);

    QSqlQuery qry(db);
    if(qry.exec(query)) ;
        //qDebug() << "Usunieto " << query;
    else
        logDbError();

    qry.finish();
}

std::string DatabaseHandler::getHashFromDbForUser(std::string user)
{
    QString query = "SELECT hash FROM users WHERE username = '";
    query.append(QString::fromStdString(user));
    query.append("'");

//    //qDebug() << query;

    Logger::getInstance().log(query, __FILE__, __LINE__);

    QSqlQuery qry(db);
    if(qry.exec(query)) ;
        //qDebug() << "Success";
    else
        logDbError();

    qry.next();
    QString hash = qry.record().value(0).toString();

    qry.finish();


    return hash.toStdString();
}

std::vector<std::string> DatabaseHandler::getAvailableTables()
{
    std::vector<std::string> availableTables;
    QSqlQuery qry(db);
    QString getHeadersQuery = "SELECT * FROM information_schema.tables";
    Logger::getInstance().log(getHeadersQuery, __FILE__, __LINE__);
    if(qry.exec(getHeadersQuery))
    {
        while(qry.next())
        {
            availableTables.push_back(qry.record().value(2).toString().toStdString());
        }
    }
    else
        logDbError();
    qry.finish();

    return availableTables;
}

std::vector<int> DatabaseHandler::processSimpleSearch(QString query)
{
    //get IDs of found records
//    std::vector<QSqlRecord> foundSqlRecords;
    std::vector<int> foundIDs;

    QSqlQuery qry(db);
    if(qry.exec(query))
    {
        while(qry.next())
        {
            foundIDs.push_back(qry.record().value(0).toInt());
        }
    //qDebug() << "Found " << foundIDs.size() << " elements";
    }
    else {
        //qDebug() << "Incorrect query format";
        logDbError();
    }

    qry.finish();


    return foundIDs;
}


