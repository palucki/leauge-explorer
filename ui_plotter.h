/********************************************************************************
** Form generated from reading UI file 'plotter.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTER_H
#define UI_PLOTTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Plotter
{
public:
    QCustomPlot *chart;

    void setupUi(QDialog *Plotter)
    {
        if (Plotter->objectName().isEmpty())
            Plotter->setObjectName(QStringLiteral("Plotter"));
        Plotter->resize(634, 388);
        chart = new QCustomPlot(Plotter);
        chart->setObjectName(QStringLiteral("chart"));
        chart->setGeometry(QRect(10, 10, 611, 361));

        retranslateUi(Plotter);

        QMetaObject::connectSlotsByName(Plotter);
    } // setupUi

    void retranslateUi(QDialog *Plotter)
    {
        Plotter->setWindowTitle(QApplication::translate("Plotter", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Plotter: public Ui_Plotter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTER_H
