#include "simplesearch.h"
#include "logger.h"
#include <QDebug>
#include "DatabaseHandler.h"
#include "foundrecord.h"

SimpleSearch::SimpleSearch(DatabaseHandler* dbh) : SearchType(dbh)
{
}

SimpleSearch::~SimpleSearch()
{
}

std::vector<FoundRecord> SimpleSearch::processQuery(QStringList arguments)
{
    //simple search expects only 3 arguments - text and table name and column name
    QString text = arguments[0];
    QString tableName = arguments[1];
    QString columnName = arguments[2];
    qDebug() << "text to find: " << text;
    qDebug() << "in: " << tableName;

    QString query = prepareQuery(columnName, tableName, text);

    qDebug() << query;
    Logger::getInstance().log(query, __FILE__, __LINE__);

    return prepareFoundRecordsVector(databaseHandler->processSimpleSearch(query),tableName);
}

QString SimpleSearch::prepareQuery(QString columnName, QString tableName, QString text)
{
    if("any column" == columnName)
    {
        return prepareQueryForAllColumns(tableName, text);
    }
    else
    {
        return prepareQueryForSingleColumn(columnName, tableName, text);
    }
}

QString SimpleSearch::prepareQueryForSingleColumn(QString columnName, QString tableName, QString text)
{
    QString query = QString("SELECT * FROM %1 WHERE ").arg(tableName);

    query.append(columnName);
    query.append(" LIKE '%");
    query.append(text);
    query.append("%'");

    return query;
}

QString SimpleSearch::prepareQueryForAllColumns(QString tableName, QString text)
{
    QString query = QString("SELECT * FROM %1 WHERE ").arg(tableName);
    QStringList headersList = databaseHandler->getColumnNamesForTable(tableName);

    for(int i = 0; i < headersList.count(); i++)
    {
        query.append(headersList[i]);
        query.append(" LIKE '%");
        query.append(text);
        query.append("%' OR ");

    }
    query.remove(query.length()-3, 3);
    return query;
}
