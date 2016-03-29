#ifndef MATHSEARCH_H
#define MATHSEARCH_H
#include "searchtype.h"

class MathSearch : public SearchType
{
public:
    MathSearch(DatabaseHandler* dbh);
    ~MathSearch();
    std::vector<FoundRecord> processQuery(QStringList arguments);
};

#endif // MATHSEARCH_H
