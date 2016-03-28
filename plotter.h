#ifndef PLOTTER_H
#define PLOTTER_H

#include <QDialog>
#include "DatabaseHandler.h"

namespace Ui {
class Plotter;
}

class Plotter : public QDialog
{
    Q_OBJECT

public:
    explicit Plotter(QWidget *parent = 0);
    ~Plotter();
    void setDatabaseHandler(DatabaseHandler *dbh);
    void showOverallAttendance();


private:
    Ui::Plotter *ui;
    DatabaseHandler* databaseHandler;
    void setPlotStyle();
    void setPlotData();
};

#endif // PLOTTER_H
