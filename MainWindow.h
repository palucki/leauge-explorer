#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemView>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include <string>
#include <map>
#include <functional>
#include "plotter.h"

class  DatabaseHandler;
class AddRecordHelper;
class LoginHelper;

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
    void editSelectedTable();
    void savebuttonClicked();
    void deletebuttonClicked();
    void addRecordButtonClicked();
    void on_resultTable_itemChanged(QTableWidgetItem *item);
    void on_signInButton_clicked();
    void on_searchButton_clicked();
    void on_allTablesasdasd_currentTextChanged(const QString &arg1);
    void on_searchTypeField_currentTextChanged(const QString &arg1);
    void enableChartButtonIfRequired();
    void on_chartButton_clicked();

private:
    Ui::MainWindow *ui;
    DatabaseHandler *databaseHandler;
    AddRecordHelper *newRecordWindow;
    LoginHelper *loginHelper;
    Plotter plotter;
    QString userIdentity;
    bool inEditingMode;
    void cleanupEnvironment();
    void connectAllSignals();
    void setEditingButtonsState(bool state);
    void setConnectionButtonsInitialState();
    void setConnectionButtonsAfterConnectState();
    void disableEditingButtonsForUnknownUser();
    void enableEditingButtonsForKnownUser();
    void showOnlyFoundRecordsInResultTable(std::vector<FoundRecord>);
    void prepareColumnsForSearch(const QString &arg1);

    void disableAdminButtons();
    void enableAdminButtons();
};

#endif // MAINWINDOW_H
