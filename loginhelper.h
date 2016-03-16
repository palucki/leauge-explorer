#ifndef LOGINHELPER_H
#define LOGINHELPER_H

#include <QGroupBox>
#include "DatabaseHandler.h"
class LoginHelper
{
public:
    LoginHelper(DatabaseHandler *dbh);
    bool userOK(std::string user, std::string pass);
private:
    DatabaseHandler *databaseHandler;
};

#endif // LOGINHELPER_H
