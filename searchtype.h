#ifndef SEARCHTYPE_H
#define SEARCHTYPE_H

#include <QString>
#include <QStringList>
#include <vector>
#include "DatabaseHandler.h"
#include "foundrecord.h"


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

