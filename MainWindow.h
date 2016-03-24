#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemView>
#include "DatabaseHandler.h"
#include "AddRecordHelper.h"
#include "loginhelper.h"
#include <string>
#include <map>
#include <functional>

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
    void updateConnectedIndicator(bool);
    void executeQueryFromEditor();
    void showTableFrom(QListWidgetItem *item);
    void showSelectedFromButton();
    void on_allTables_itemDoubleClicked(QListWidgetItem *item);
    void editSelectedTable();
    void savebuttonClicked();
    void deletebuttonClicked();
    void addRecordButtonClicked();
    void on_resultTable_itemChanged(QTableWidgetItem *item);
    void on_signInButton_clicked();

    void on_searchButton_clicked();

    void on_allTablesasdasd_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    DatabaseHandler *databaseHandler;
    AddRecordHelper *newRecordWindow;
    LoginHelper *loginHelper;
    QString userIdentity;
    bool inEditingMode;
    void cleanupEnvironment();
    void connectAllSignals();
    void setEditingButtonsState(bool state);
    void setConnectionButtonsInitialState();
    void setConnectionButtonsAfterConnectState();
};

#endif // MAINWINDOW_H
