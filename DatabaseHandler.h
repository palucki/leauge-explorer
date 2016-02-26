#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QDebug>
#include <QtSql>

class DatabaseHandler
{
public:
    DatabaseHandler();
    void connectToDatabase();
    void disconnectFromDatabase();
    bool getConnectionStatus() {return db.isOpen(); }
private:
    QSqlDatabase db;
};

#endif // DATABASEHANDLER_H
