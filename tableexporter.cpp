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

        for(auto i = 0; i < table->rowCount(); i++)
        {
            for(auto j = 0; j < table->columnCount(); j++)
            {
                tableFile << table->itemAt(i,j)->text().toStdString() << ",";
                qDebug() << i << j;
            }
            tableFile << std::endl;
        }

        tableFile.close();
    }
    else
        qDebug() << "Can't open file:" << fileName;
}

