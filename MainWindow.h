#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DatabaseHandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setDatabaseHandler(DatabaseHandler* dbh);
    ~MainWindow();

private slots:
    void connectToDatabase();
    void disconnectFromDatabase();
    void showLeaugeTable();
    void updateConnectedIndicator(bool);
    void executeQueryFromEditor();
    void showSelectedTable();
private:
    Ui::MainWindow *ui;
    DatabaseHandler *databaseHandler;
};




#endif // MAINWINDOW_H
