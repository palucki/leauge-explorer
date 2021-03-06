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

    QString query = prepareQuery(tableName, columnName, text1, operand, text2);

    qDebug() << query;
    Logger::getInstance().logQuery(query, __FILE__, __LINE__);

    return prepareFoundRecordsVector(databaseHandler->processSimpleSearch(query),tableName);
}

QString LogicalSearch::prepareQuery(QString tableName, QString columnName, QString text1, QString operand, QString text2)
{
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

    return query;
}
