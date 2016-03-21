#include "simplesearch.h"

SimpleSearch::SimpleSearch(DatabaseHandler* dbh) : SearchType(dbh)
{
}

SimpleSearch::~SimpleSearch()
{
}

std::vector<FoundRecord> SimpleSearch::processQuery(QStringList arguments)
{
    std::vector<FoundRecord> a;
    return a;
}
