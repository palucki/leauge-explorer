#include "searchtype.h"

SearchType::SearchType(DatabaseHandler* dbH)
{
    databaseHandler = dbH;
}

SearchType::~SearchType()
{}

std::vector<FoundRecord> SearchType::prepareFoundRecordsVector(std::vector<int> foundIDs, QString tableName)
{
    std::vector<FoundRecord> foundRecords;

    for(auto it = foundIDs.begin(); it != foundIDs.end(); it++)
    {
        foundRecords.push_back(FoundRecord(tableName, *it));
    }

    return foundRecords;
}
