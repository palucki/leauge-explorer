#include "mathsearch.h"
#include "logger.h"
#include <QDebug>
#include "DatabaseHandler.h"

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

    QString query = QString("SELECT * FROM %1 WHERE %2 %3 '%4'")
            .arg(tableName).arg(columnName).arg(operand).arg(value);

    //qDebug() << query;
    Logger::getInstance().log(query, __FILE__, __LINE__);
    std::vector<int> foundIDs = databaseHandler->processSimpleSearch(query);

    return prepareFoundRecordsVector(foundIDs,tableName);
}
