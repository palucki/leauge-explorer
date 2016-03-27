#include "plotter.h"
#include "ui_plotter.h"

Plotter::Plotter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Plotter)
{
    ui->setupUi(this);
}

Plotter::~Plotter()
{
    delete ui;
}

void Plotter::showOverallAttendance()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->chart->addGraph();
    ui->chart->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->chart->xAxis->setLabel("x");
    ui->chart->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->chart->xAxis->setRange(-1, 1);
    ui->chart->yAxis->setRange(0, 1);
    ui->chart->replot();
}
