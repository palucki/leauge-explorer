#ifndef LOGICALSEARCH_H
#define LOGICALSEARCH_H

#include "searchtype.h"

class LogicalSearch : public SearchType
{
public:
    LogicalSearch(DatabaseHandler* dbh);
    ~LogicalSearch();
    std::vector<FoundRecord> processQuery(QStringList arguments);
};

#endif // LOGICALSEARCH_H
