#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QDebug>
#include <QtSql>
#include <QTableWidget>
#include <QListWidget>

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
    void showAvailableTablesFromDatabaseIn(QListWidget* list);
    void clearAvailableTablesList(QListWidget* list);
    void showTableInResults(const QString tableName);
    void addTable(const QString tableName);
private:
    QSqlDatabase db;
    QTableWidget* resultTable;
    int prepareColumns(QTableWidget* resultTable, QSqlQuery qry);
    void prepareColumns(QSqlQuery qry);
    void fillTableWithQueryData(QSqlQuery qry);
    void logDbError();
};

#endif // DATABASEHANDLER_H
