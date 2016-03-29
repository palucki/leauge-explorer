#include "simplesearch.h"
#include "logger.h"

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

    QString query = QString("SELECT * FROM %1 WHERE ").arg(tableName);

    if("any column" == columnName)
    {
        QStringList headersList = databaseHandler->getColumnNamesForTable(tableName);

        for(int i = 0; i < headersList.count(); i++)
        {
            query.append(headersList[i]);
            query.append(" LIKE '%");
            query.append(text);
            query.append("%' OR ");

        }
        query.remove(query.length()-3, 3); //remove last "OR "
    }
    else
    {
        query.append(columnName);
        query.append(" LIKE '%");
        query.append(text);
        query.append("%'");
    }

    qDebug() << query;
    Logger::getInstance().log(query, __FILE__, __LINE__);
    std::vector<int> foundIDs = databaseHandler->processSimpleSearch(query);

    std::vector<FoundRecord> foundRecords;

    for(auto it = foundIDs.begin(); it != foundIDs.end(); it++)
    {
        foundRecords.push_back(FoundRecord(tableName, *it));
    }
    qDebug() << "zero elements test";
    return foundRecords;
}
