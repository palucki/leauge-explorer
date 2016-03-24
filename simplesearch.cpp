#include "simplesearch.h"

SimpleSearch::SimpleSearch(DatabaseHandler* dbh) : SearchType(dbh)
{
}

SimpleSearch::~SimpleSearch()
{
}

std::vector<FoundRecord> SimpleSearch::processQuery(QStringList arguments)
{
    //simple search expects only 2 arguments - text and table id

    QString text = arguments[0];
    QString whereToSearch = arguments[1];
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

    QString query = QString("SELECT id FROM %1 WHERE %2 LIKE %3")
                        .arg(whereToSearch)
                        .arg("id")
                        .arg(text);

    std::vector<QSqlRecord> found = databaseHandler->processSimpleSearch(query);
//    std::vector<std::string> availableTables = databaseHandler->getAvailableTables();
    std::vector<FoundRecord> a;
    for(int i = 0 ; i < found.size(); i++)
    {
        //qry.record().value(2).toString().toStdString()
        a.push_back(FoundRecord(whereToSearch, found[i].value(0).toInt())); //value0 to id, value1 to cos tam
        qDebug() << "Found: " << found[i].value(0).toInt();
        qDebug() << "In table: " << whereToSearch;
    }


    return a;
}
