#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QDebug>
#include <QtSql>
#include <QTableWidget>
#include <QListWidget>
#include <memory>
#include "foundrecord.h"

class DatabaseHandler
{
public:
    DatabaseHandler()  ;
    void setDatabase();
    ~DatabaseHandler();
    void connectToDatabase();
    void disconnectFromDatabase();
    bool getConnectionStatus() {return db.isOpen(); }
    void sendQuery();
    void executeQuery(const QString query);
    void setResultTable(QTableWidget* resTab);
    void showAvailableTablesFromDatabaseIn(QComboBox* box);
    void clearAvailableTablesList(QComboBox* box);
    void showTableInResults(const QString tableName);
    void addUpdateQueryToQueriesList(int row, int column);
    void saveChangesToDatabase();
    int getNextId(const QString);
    void insertNewRow(QStringList fields);
    void refreshTable();
    void removeCurrentRow();
    std::string getHashFromDbForUser(std::string user);
    std::vector<std::string> getAvailableTables();
    std::vector<int> processSimpleSearch(QString query);
    QStringList getColumnNamesForTable(QString tableName);
    void showFoundRecordsInResultTable(std::vector <FoundRecord> fr);

private:
    QSqlDatabase db;
    QString currentTable;
    QTableWidget* resultTable;
    int nextId;
    void prepareColumns(const QSqlQuery qry);
    void fillTableWithQueryData(QSqlQuery qry);
    void logDbError();
    void rowIsCorrect(QString query, bool willBeInserted);
    bool asdas(QString query);
    bool rowIsAcceptable(QString query);
    QStringList queriesList;
};

#endif // DATABASEHANDLER_H
