#include "tableexporter.h"
#include <QString>
#include <QTableWidget>
#include <QDebug>
#include <fstream>

TableExporter::TableExporter()
{
}

void TableExporter::saveTableInCsv(QString fileName, QTableWidget* table)
{
    std::ofstream tableFile;
    tableFile.open(fileName.toStdString(), std::ios::out | std::ios::trunc);
    if(tableFile.is_open())
    {
        qDebug() << "Table " << table->objectName() << " will be exported";

        tableFile.close();
    }
    else
        qDebug() << "Can't open file:" << fileName;
}

