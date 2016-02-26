#include "MainWindow.h"
#include <QApplication>
#include "DatabaseHandler.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseHandler dbh;
    MainWindow w;

    w.setDatabaseHandler(&dbh);

    w.show();

    return a.exec();
}
