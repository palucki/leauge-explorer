/********************************************************************************
** Form generated from reading UI file 'addrecordhelper.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRECORDHELPER_H
#define UI_ADDRECORDHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddRecordHelper
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QTableWidget *newRecordTable;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveNewRecordButton;
    QPushButton *cancelAddingButton;
    QLabel *label;

    void setupUi(QDialog *AddRecordHelper)
    {
        if (AddRecordHelper->objectName().isEmpty())
            AddRecordHelper->setObjectName(QStringLiteral("AddRecordHelper"));
        AddRecordHelper->resize(588, 166);
        widget = new QWidget(AddRecordHelper);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 571, 132));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        newRecordTable = new QTableWidget(widget);
        newRecordTable->setObjectName(QStringLiteral("newRecordTable"));

        gridLayout->addWidget(newRecordTable, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        saveNewRecordButton = new QPushButton(widget);
        saveNewRecordButton->setObjectName(QStringLiteral("saveNewRecordButton"));

        horizontalLayout->addWidget(saveNewRecordButton);

        cancelAddingButton = new QPushButton(widget);
        cancelAddingButton->setObjectName(QStringLiteral("cancelAddingButton"));

        horizontalLayout->addWidget(cancelAddingButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(AddRecordHelper);

        QMetaObject::connectSlotsByName(AddRecordHelper);
    } // setupUi

    void retranslateUi(QDialog *AddRecordHelper)
    {
        AddRecordHelper->setWindowTitle(QApplication::translate("AddRecordHelper", "Add record", 0));
        saveNewRecordButton->setText(QApplication::translate("AddRecordHelper", "Save record", 0));
        cancelAddingButton->setText(QApplication::translate("AddRecordHelper", "Cancel", 0));
        label->setText(QApplication::translate("AddRecordHelper", "Insert record data:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddRecordHelper: public Ui_AddRecordHelper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRECORDHELPER_H
