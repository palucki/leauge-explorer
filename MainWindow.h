#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemView>
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
    void updateConnectedIndicator(bool);
    void executeQueryFromEditor();
    void showTableFrom(QListWidgetItem *item);
    void showSelectedFromButton();
    void on_allTables_itemDoubleClicked(QListWidgetItem *item);
    void editSelectedTable();
    void savebuttonClicked();
    void deletebuttonClicked();
    void addRecordButtonClicked();

    void on_resultTable_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
    DatabaseHandler *databaseHandler;
    void cleanupEnvironment();
    void connectAllSignals();
    void setEditingButtonsState(bool state);
    void setConnectionButtonsInitialState();
    void setConnectionButtonsAfterConnectState();
};




#endif // MAINWINDOW_H
