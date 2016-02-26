#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void connectToDatabase();
    void disconnectFromDatabase();
    void showLeaugeTable();
    void updateConnectedIndicator(bool);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};




#endif // MAINWINDOW_H
