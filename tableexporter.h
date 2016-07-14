#ifndef TABLEEXPORTER_H
#define TABLEEXPORTER_H

class QString;
class QTableWidget;

class TableExporter
{
public:
    TableExporter();
    void saveTableInCsv(QString fileName, QTableWidget* table);
};

#endif // TABLEEXPORTER_H
