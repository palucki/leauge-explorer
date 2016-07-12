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
};

#endif // SIMPLESEARCH_H
