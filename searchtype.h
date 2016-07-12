#ifndef SEARCHTYPE_H
#define SEARCHTYPE_H

#include <QString>
#include <QStringList>
#include <vector>
#include "foundrecord.h"

class DatabaseHandler;

class SearchType
{
public:
    SearchType(DatabaseHandler* dbH);
    virtual ~SearchType();
    virtual std::vector<FoundRecord> processQuery(QStringList arguments) = 0;
    std::vector<FoundRecord> prepareFoundRecordsVector(std::vector<int> foundIDs, QString tableName);
protected:
    DatabaseHandler* databaseHandler;
};

#endif // SEARCHTYPE_H
