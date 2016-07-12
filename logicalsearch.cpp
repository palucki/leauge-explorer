#include "logicalsearch.h"
#include "logger.h"
#include "DatabaseHandler.h"
#include "foundrecord.h"

LogicalSearch::LogicalSearch(DatabaseHandler* dbh) : SearchType(dbh)
{

}


LogicalSearch::~LogicalSearch()
{

}

std::vector<FoundRecord> LogicalSearch::processQuery(QStringList arguments)
{
    //Logical search expects 5 arguments - tablename, column name, text1, operand, text2
    QString tableName = arguments[0];
    QString columnName = arguments[1];
    QString text1 = arguments[2];
    QString operand = arguments[3];
    QString text2 = arguments[4];

    QString query = QString("SELECT * FROM %1 WHERE ").arg(tableName);

    if("any column" == columnName)
    {
        QStringList headersList = databaseHandler->getColumnNamesForTable(tableName);
        qDebug() << headersList;
        for(int i = 0; i < headersList.count(); i++)
        {
            query.append(headersList[i]);
            query.append(" LIKE '%");
            query.append(text1);
            query.append("%' ");
            query.append(operand);
            query.append(" ");
            query.append(headersList[i]);
            query.append(" LIKE '%");
            query.append(text2);
            query.append("%' OR ");
        }

        query.remove(query.length()-3, 3); //remove last "OR "
    }
    else
    {
        query.append(columnName).append(" LIKE '%").append(text1).append("%' ")
             .append(operand).append(" ").append(columnName).append(" LIKE '%").append(text2)
             .append("%'");
    }

    qDebug() << query;
    Logger::getInstance().log(query, __FILE__, __LINE__);
    std::vector<int> foundIDs = databaseHandler->processSimpleSearch(query);

    std::vector<FoundRecord> foundRecords;

    for(auto it = foundIDs.begin(); it != foundIDs.end(); it++)
    {
        foundRecords.push_back(FoundRecord(tableName, *it));
    }

    return foundRecords;
}
