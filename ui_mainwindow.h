/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "digitalclock.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *resultTable;
    QGroupBox *groupBox;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *searchFieldsLayout;
    QLineEdit *searchLineEdit;
    QComboBox *searchOptionBox;
    QLineEdit *searchLineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *searchTypeField;
    QLabel *label_8;
    QComboBox *columnForSearch;
    QPushButton *searchButton;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *allTablesasdasd;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *addRecordButton;
    QPushButton *deleteButton;
    QPushButton *saveButton;
    QPushButton *editModeButton;
    QVBoxLayout *verticalLayout_4;
    QPlainTextEdit *queryEditor;
    QPushButton *executeQueryButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *loginGroupBox;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLineEdit *usernameLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *signInButton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QPushButton *connectButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *connectionIndicator;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *disconnectButton;
    QPushButton *exitButton;
    DigitalClock *currentTime;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *chartButton;
    QPushButton *exportTableButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(890, 620);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        resultTable = new QTableWidget(centralWidget);
        resultTable->setObjectName(QStringLiteral("resultTable"));
        resultTable->setEnabled(true);
        resultTable->setGeometry(QRect(240, 300, 631, 251));
        resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        resultTable->setSortingEnabled(true);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(240, 10, 631, 271));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 150, 611, 111));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 591, 81));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchFieldsLayout = new QHBoxLayout();
        searchFieldsLayout->setSpacing(6);
        searchFieldsLayout->setObjectName(QStringLiteral("searchFieldsLayout"));
        searchLineEdit = new QLineEdit(layoutWidget);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));
        searchLineEdit->setEnabled(false);
        QFont font;
        font.setPointSize(9);
        searchLineEdit->setFont(font);

        searchFieldsLayout->addWidget(searchLineEdit);

        searchOptionBox = new QComboBox(layoutWidget);
        searchOptionBox->setObjectName(QStringLiteral("searchOptionBox"));
        searchOptionBox->setEnabled(false);
        searchOptionBox->setFont(font);

        searchFieldsLayout->addWidget(searchOptionBox);

        searchLineEdit_2 = new QLineEdit(layoutWidget);
        searchLineEdit_2->setObjectName(QStringLiteral("searchLineEdit_2"));
        searchLineEdit_2->setEnabled(false);
        searchLineEdit_2->setFont(font);

        searchFieldsLayout->addWidget(searchLineEdit_2);


        verticalLayout_3->addLayout(searchFieldsLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        searchTypeField = new QComboBox(layoutWidget);
        searchTypeField->setObjectName(QStringLiteral("searchTypeField"));
        searchTypeField->setEnabled(false);
        searchTypeField->setMinimumSize(QSize(100, 0));
        searchTypeField->setFont(font);

        horizontalLayout_2->addWidget(searchTypeField);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_2->addWidget(label_8);

        columnForSearch = new QComboBox(layoutWidget);
        columnForSearch->setObjectName(QStringLiteral("columnForSearch"));
        columnForSearch->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(columnForSearch->sizePolicy().hasHeightForWidth());
        columnForSearch->setSizePolicy(sizePolicy1);
        columnForSearch->setMinimumSize(QSize(100, 0));
        columnForSearch->setFont(font);

        horizontalLayout_2->addWidget(columnForSearch);

        searchButton = new QPushButton(layoutWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        searchButton->setFont(font1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/MyFiles/images/png/data-search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon);
        searchButton->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(searchButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 20, 611, 131));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 592, 101));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout);

        allTablesasdasd = new QComboBox(layoutWidget1);
        allTablesasdasd->setObjectName(QStringLiteral("allTablesasdasd"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(allTablesasdasd->sizePolicy().hasHeightForWidth());
        allTablesasdasd->setSizePolicy(sizePolicy3);
        allTablesasdasd->setMinimumSize(QSize(200, 0));
        allTablesasdasd->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setPointSize(10);
        allTablesasdasd->setFont(font2);

        verticalLayout_5->addWidget(allTablesasdasd);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        addRecordButton = new QPushButton(layoutWidget1);
        addRecordButton->setObjectName(QStringLiteral("addRecordButton"));
        addRecordButton->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(addRecordButton->sizePolicy().hasHeightForWidth());
        addRecordButton->setSizePolicy(sizePolicy4);
        addRecordButton->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MyFiles/images/png/bible-with-cross-symbol-variant.png"), QSize(), QIcon::Normal, QIcon::Off);
        addRecordButton->setIcon(icon1);
        addRecordButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(addRecordButton, 0, 0, 1, 1);

        deleteButton = new QPushButton(layoutWidget1);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setEnabled(false);
        sizePolicy4.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy4);
        deleteButton->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MyFiles/images/png/data-storage-drive-with-cross-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);
        deleteButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(deleteButton, 1, 0, 1, 1);

        saveButton = new QPushButton(layoutWidget1);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setEnabled(false);
        sizePolicy4.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy4);
        saveButton->setFont(font);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MyFiles/images/png/data-storage.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon3);
        saveButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(saveButton, 1, 1, 1, 1);

        editModeButton = new QPushButton(layoutWidget1);
        editModeButton->setObjectName(QStringLiteral("editModeButton"));
        editModeButton->setEnabled(false);
        sizePolicy4.setHeightForWidth(editModeButton->sizePolicy().hasHeightForWidth());
        editModeButton->setSizePolicy(sizePolicy4);
        editModeButton->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MyFiles/images/png/data-storage-disc.png"), QSize(), QIcon::Normal, QIcon::Off);
        editModeButton->setIcon(icon4);
        editModeButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(editModeButton, 0, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        queryEditor = new QPlainTextEdit(layoutWidget1);
        queryEditor->setObjectName(QStringLiteral("queryEditor"));
        queryEditor->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(queryEditor->sizePolicy().hasHeightForWidth());
        queryEditor->setSizePolicy(sizePolicy5);
        queryEditor->setMinimumSize(QSize(0, 0));
        queryEditor->setMaximumSize(QSize(16777215, 40));
        QFont font3;
        font3.setPointSize(8);
        queryEditor->setFont(font3);

        verticalLayout_4->addWidget(queryEditor);

        executeQueryButton = new QPushButton(layoutWidget1);
        executeQueryButton->setObjectName(QStringLiteral("executeQueryButton"));
        executeQueryButton->setEnabled(false);
        sizePolicy5.setHeightForWidth(executeQueryButton->sizePolicy().hasHeightForWidth());
        executeQueryButton->setSizePolicy(sizePolicy5);
        executeQueryButton->setMinimumSize(QSize(0, 0));
        executeQueryButton->setFont(font);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MyFiles/images/png/database-edition.png"), QSize(), QIcon::Normal, QIcon::Off);
        executeQueryButton->setIcon(icon5);
        executeQueryButton->setIconSize(QSize(25, 25));

        verticalLayout_4->addWidget(executeQueryButton);


        horizontalLayout_4->addLayout(verticalLayout_4);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 211, 341));
        verticalLayout_7 = new QVBoxLayout(layoutWidget2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        loginGroupBox = new QGroupBox(layoutWidget2);
        loginGroupBox->setObjectName(QStringLiteral("loginGroupBox"));
        loginGroupBox->setMinimumSize(QSize(0, 50));
        loginGroupBox->setMaximumSize(QSize(16777215, 150));
        layoutWidget3 = new QWidget(loginGroupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 191, 111));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_2);

        usernameLineEdit = new QLineEdit(layoutWidget3);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setEnabled(false);
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(usernameLineEdit->sizePolicy().hasHeightForWidth());
        usernameLineEdit->setSizePolicy(sizePolicy6);
        usernameLineEdit->setMinimumSize(QSize(0, 30));
        usernameLineEdit->setMaximumSize(QSize(100, 16777215));
        usernameLineEdit->setFont(font);

        horizontalLayout_7->addWidget(usernameLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_4);

        passwordLineEdit = new QLineEdit(layoutWidget3);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEnabled(false);
        sizePolicy6.setHeightForWidth(passwordLineEdit->sizePolicy().hasHeightForWidth());
        passwordLineEdit->setSizePolicy(sizePolicy6);
        passwordLineEdit->setMinimumSize(QSize(0, 30));
        passwordLineEdit->setMaximumSize(QSize(100, 16777215));
        passwordLineEdit->setFont(font);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(passwordLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        signInButton = new QPushButton(layoutWidget3);
        signInButton->setObjectName(QStringLiteral("signInButton"));
        signInButton->setEnabled(false);
        sizePolicy5.setHeightForWidth(signInButton->sizePolicy().hasHeightForWidth());
        signInButton->setSizePolicy(sizePolicy5);
        signInButton->setMinimumSize(QSize(0, 20));
        signInButton->setMaximumSize(QSize(16777215, 60));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        signInButton->setFont(font4);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/MyFiles/images/png/interface.png"), QSize(), QIcon::Normal, QIcon::Off);
        signInButton->setIcon(icon6);
        signInButton->setIconSize(QSize(25, 25));

        horizontalLayout_9->addWidget(signInButton);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_7->addWidget(loginGroupBox);

        groupBox_2 = new QGroupBox(layoutWidget2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        layoutWidget4 = new QWidget(groupBox_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(11, 21, 197, 151));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        connectButton = new QPushButton(layoutWidget4);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        sizePolicy5.setHeightForWidth(connectButton->sizePolicy().hasHeightForWidth());
        connectButton->setSizePolicy(sizePolicy5);
        connectButton->setMinimumSize(QSize(0, 0));
        connectButton->setMaximumSize(QSize(16777215, 60));
        connectButton->setFont(font4);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/MyFiles/images/png/folder-silhouette-with-arrow-pointing-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectButton->setIcon(icon7);
        connectButton->setIconSize(QSize(25, 25));
        connectButton->setFlat(false);

        verticalLayout->addWidget(connectButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        connectionIndicator = new QCheckBox(layoutWidget4);
        connectionIndicator->setObjectName(QStringLiteral("connectionIndicator"));
        connectionIndicator->setEnabled(true);
        sizePolicy1.setHeightForWidth(connectionIndicator->sizePolicy().hasHeightForWidth());
        connectionIndicator->setSizePolicy(sizePolicy1);
        connectionIndicator->setLayoutDirection(Qt::LeftToRight);
        connectionIndicator->setAutoFillBackground(false);
        connectionIndicator->setStyleSheet(QLatin1String("QCheckBox::indicator {\n"
"    background-color: red;\n"
"}"));
        connectionIndicator->setIconSize(QSize(20, 20));
        connectionIndicator->setCheckable(false);

        horizontalLayout_3->addWidget(connectionIndicator);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        disconnectButton = new QPushButton(layoutWidget4);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));
        disconnectButton->setEnabled(false);
        sizePolicy5.setHeightForWidth(disconnectButton->sizePolicy().hasHeightForWidth());
        disconnectButton->setSizePolicy(sizePolicy5);
        disconnectButton->setMinimumSize(QSize(0, 0));
        disconnectButton->setMaximumSize(QSize(16777215, 60));
        disconnectButton->setFont(font4);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/MyFiles/images/png/folder-with-close-or-delete-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        disconnectButton->setIcon(icon8);
        disconnectButton->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(disconnectButton);

        exitButton = new QPushButton(layoutWidget4);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        sizePolicy5.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy5);
        exitButton->setMinimumSize(QSize(0, 0));
        exitButton->setMaximumSize(QSize(16777215, 60));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        exitButton->setFont(font5);
        exitButton->setAutoFillBackground(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/MyFiles/images/png/direction.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon9);
        exitButton->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(exitButton);


        verticalLayout_7->addWidget(groupBox_2);

        currentTime = new DigitalClock(centralWidget);
        currentTime->setObjectName(QStringLiteral("currentTime"));
        currentTime->setGeometry(QRect(80, 370, 71, 31));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(580, 560, 291, 35));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        chartButton = new QPushButton(horizontalLayoutWidget);
        chartButton->setObjectName(QStringLiteral("chartButton"));
        chartButton->setEnabled(false);
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(chartButton->sizePolicy().hasHeightForWidth());
        chartButton->setSizePolicy(sizePolicy7);
        chartButton->setMinimumSize(QSize(0, 0));
        chartButton->setMaximumSize(QSize(16777215, 40));
        chartButton->setFont(font);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/MyFiles/images/png/arrow-made-up-of-connectors-and-lines.png"), QSize(), QIcon::Normal, QIcon::Off);
        chartButton->setIcon(icon10);
        chartButton->setIconSize(QSize(25, 25));

        horizontalLayout_5->addWidget(chartButton);

        exportTableButton = new QPushButton(horizontalLayoutWidget);
        exportTableButton->setObjectName(QStringLiteral("exportTableButton"));
        exportTableButton->setEnabled(false);
        sizePolicy7.setHeightForWidth(exportTableButton->sizePolicy().hasHeightForWidth());
        exportTableButton->setSizePolicy(sizePolicy7);
        exportTableButton->setMinimumSize(QSize(0, 0));
        exportTableButton->setMaximumSize(QSize(16777215, 40));
        exportTableButton->setFont(font);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/MyFiles/images/png/coins-stack-with-arrows-in-different-directions.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportTableButton->setIcon(icon11);
        exportTableButton->setIconSize(QSize(25, 25));

        horizontalLayout_5->addWidget(exportTableButton);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        resultTable->raise();
        groupBox->raise();
        currentTime->raise();
        horizontalLayoutWidget->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Leauge Explorer", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Database operations", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Search", 0));
        searchLineEdit->setText(QString());
        searchLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "(eg. Krak\303\263w)", 0));
        searchLineEdit_2->setText(QString());
        searchLineEdit_2->setPlaceholderText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Query type:", 0));
        searchTypeField->clear();
        searchTypeField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "simple", 0)
         << QApplication::translate("MainWindow", "mathematical", 0)
         << QApplication::translate("MainWindow", "logical", 0)
        );
        label_8->setText(QApplication::translate("MainWindow", "in column", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Modify", 0));
        label->setText(QApplication::translate("MainWindow", "Available tables", 0));
        addRecordButton->setText(QApplication::translate("MainWindow", "Add record", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete record", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        editModeButton->setText(QApplication::translate("MainWindow", "Edit mode", 0));
        queryEditor->setPlainText(QString());
        queryEditor->setPlaceholderText(QApplication::translate("MainWindow", "(Insert your custom query)", 0));
        executeQueryButton->setText(QApplication::translate("MainWindow", "Execute custom query", 0));
        loginGroupBox->setTitle(QApplication::translate("MainWindow", "Login", 0));
        label_2->setText(QApplication::translate("MainWindow", "User name", 0));
        usernameLineEdit->setText(QApplication::translate("MainWindow", "user", 0));
        label_4->setText(QApplication::translate("MainWindow", "Password", 0));
        passwordLineEdit->setText(QString());
        signInButton->setText(QApplication::translate("MainWindow", "Sign in", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Connection", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect to Database", 0));
        connectionIndicator->setText(QApplication::translate("MainWindow", "Connection state", 0));
        disconnectButton->setText(QApplication::translate("MainWindow", "Disconnect from Database", 0));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
        chartButton->setText(QApplication::translate("MainWindow", "Plot", 0));
        exportTableButton->setText(QApplication::translate("MainWindow", "Export", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
