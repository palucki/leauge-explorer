#include "mathsearch.h"
#include "logger.h"

MathSearch::MathSearch(DatabaseHandler *dbh) : SearchType(dbh)
{

}

MathSearch::~MathSearch()
{

}

std::vector<FoundRecord> MathSearch::processQuery(QStringList arguments)
{
    //math search expects 4 arguments - tablename, column name, operand, value
    QString tableName = arguments[0];
    QString columnName = arguments[1];
    QString operand = arguments[2];
    QString value = arguments[3];


    QString query = QString("SELECT * FROM %1 WHERE %2 %3").arg(tableName).arg(columnName).arg(operand);
    query.append("'");
    query.append(value);
    query.append("'");


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
