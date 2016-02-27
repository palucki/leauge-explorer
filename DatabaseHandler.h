#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QDebug>
#include <QtSql>
#include <QTableWidget>

class DatabaseHandler
{
public:
    DatabaseHandler();
    void connectToDatabase();
    void disconnectFromDatabase();
    bool getConnectionStatus() {return db.isOpen(); }
    void sendQuery();
    void executeQuery(const QString query);
    void setResultTable(QTableWidget* resTab);
private:
    QSqlDatabase db;
    QTableWidget* resultTable;
    int prepareColumns(QTableWidget* resultTable, QSqlQuery qry);
    void prepareColumns(QSqlQuery qry);
    void fillTableWithQueryData(QSqlQuery qry);
};

#endif // DATABASEHANDLER_H
