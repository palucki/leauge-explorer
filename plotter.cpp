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

void Plotter::setDatabaseHandler(DatabaseHandler *dbh)
{
    databaseHandler = dbh;
}

void Plotter::setPlotStyle()
{
    QCPScatterStyle myScatter;
    myScatter.setShape(QCPScatterStyle::ssCircle);
    myScatter.setPen(QPen(Qt::blue));
    myScatter.setBrush(Qt::white);
    myScatter.setSize(5);
    ui->chart->graph(0)->setScatterStyle(myScatter);

    ui->chart->xAxis->setLabel("Numer kolejki");
    ui->chart->yAxis->setLabel("Oglądalność");
    ui->chart->xAxis->setRange(0, 20);
    ui->chart->yAxis->setRange(0, 30000);
}

void Plotter::setPlotData()
{
    std::vector< std::pair<double, double > > data = databaseHandler->getOverallAttendance();

    QVector<double> x, y; // initialize with entries 0..100
    x.resize(static_cast<int>(data.size()));
    y.resize(static_cast<int>(data.size()));

    for (int i=0; i<data.size(); ++i)
    {
        x[i] = data[i].first;
        y[i] = data[i].second;
    }

    ui->chart->addGraph();
    ui->chart->graph(0)->setData(x, y);
}

void Plotter::showOverallAttendance()
{
    setPlotData();
    setPlotStyle();
    ui->chart->replot();
}
