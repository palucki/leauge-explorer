#ifndef SIMPLESEARCH_H
#define SIMPLESEARCH_H

#include "searchtype.h"
#include "foundrecord.h"
class DatabaseHandler;


class SimpleSearch : public SearchType
{
public:
    SimpleSearch(DatabaseHandler* dbh);
    ~SimpleSearch();
    std::vector<FoundRecord> processQuery(QStringList arguments);
private:
    QString prepareQuery(QString columnName, QString text, QString tableName);
    QString prepareQueryForAllColumns(QString tableName, QString text);
    QString prepareQueryForSingleColumn(QString columnName, QString tableName, QString text);
};

#endif // SIMPLESEARCH_H
