#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QDebug>
#include <QtSql>
#include <QTableWidget>
#include <QListWidget>
#include <memory>

class FoundRecord;

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
    void setResultTable(QTableWidget* resTab);                  //niestety blad, nie powinien nic rysowac database handler
    void showAvailableTablesFromDatabaseIn(QComboBox* box);     //niestety blad, nie powinien nic rysowac database handler
    void clearAvailableTablesList(QComboBox* box);              //niestety blad, nie powinien nic rysowac database handler
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
    std::vector< std::pair<double, double> > getOverallAttendance();

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
    void showQueryResults(QSqlQuery qry);
    void executeGivenQueryAndShowResults(QSqlQuery qry, QString query);
};

#endif // DATABASEHANDLER_H
