#ifndef LOGICALSEARCH_H
#define LOGICALSEARCH_H

#include "searchtype.h"

class LogicalSearch : public SearchType
{
public:
    LogicalSearch(DatabaseHandler* dbh);
    ~LogicalSearch();
    std::vector<FoundRecord> processQuery(QStringList arguments);
private:
    QString prepareQuery(QString tableName, QString columnName, QString text1, QString operand, QString text2);
};

#endif // LOGICALSEARCH_H
