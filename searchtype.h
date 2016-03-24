#ifndef SEARCHTYPE_H
#define SEARCHTYPE_H

#include <QString>
#include <QStringList>
#include <vector>
#include "DatabaseHandler.h"

class FoundRecord
{
public:
    FoundRecord(QString tablName, int rw) : tableName(tablName), row(rw) {}
    QString getTableName() { return tableName;}
    int getRow() { return row; }
private:
    QString tableName;
    int row;
};

class SearchType
{
public:
    SearchType(DatabaseHandler* dbH) {databaseHandler = dbH; }
    virtual ~SearchType() { }
    virtual std::vector<FoundRecord> processQuery(QStringList arguments) = 0;
protected:
    DatabaseHandler* databaseHandler;
};


#endif // SEARCHTYPE_H

