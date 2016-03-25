#ifndef FOUNDRECORD_H
#define FOUNDRECORD_H

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

#endif // FOUNDRECORD_H

