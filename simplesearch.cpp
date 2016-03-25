#include "simplesearch.h"

SimpleSearch::SimpleSearch(DatabaseHandler* dbh) : SearchType(dbh)
{
}

SimpleSearch::~SimpleSearch()
{
}

std::vector<FoundRecord> SimpleSearch::processQuery(QStringList arguments)
{
    //simple search expects only 3 arguments - text and table id and column name
    QString text = arguments[0];
    QString whereToSearch = arguments[1];
    QString columnName = arguments[2];
    qDebug() << "text to find: " << text;
    qDebug() << "in: " << whereToSearch;

    QString tableName;
    if("whole database" == whereToSearch)
    {
        qDebug() << "Bedziemy szukac w calej";
    }
    else
    {
        tableName = whereToSearch;
    }
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
    std::vector<QSqlRecord> found = databaseHandler->processSimpleSearch(query);

//    std::vector<std::string> availableTables = databaseHandler->getAvailableTables();
    std::vector<FoundRecord> a;
//    for(int i = 0 ; i < found.size(); i++)
//    {
//        //qry.record().value(2).toString().toStdString()
//        a.push_back(FoundRecord(whereToSearch, found[i].value(0).toInt())); //value0 to id, value1 to cos tam
//        qDebug() << "Found: " << found[i].value(0).toInt();
//        qDebug() << "In table: " << whereToSearch;
//    }



    return a;
}
