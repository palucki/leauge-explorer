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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *resultTable;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *chartButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *allTablesasdasd;
    QGridLayout *gridLayout;
    QPushButton *addRecordButton;
    QPushButton *deleteButton;
    QPushButton *saveButton;
    QPushButton *editModeButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *searchTypeField;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *searchFieldsLayout;
    QLineEdit *searchLineEdit;
    QComboBox *searchOptionBox;
    QLineEdit *searchLineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_8;
    QComboBox *columnForSearch;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *searchButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton;
    QWidget *tab_2;
    QGroupBox *loginGroupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *signInButton;
    QGroupBox *advancedOptions;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QPlainTextEdit *queryEditor;
    QSpacerItem *verticalSpacer;
    QPushButton *executeQueryButton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QPushButton *connectButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *connectionIndicator;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *disconnectButton;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(935, 506);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        resultTable = new QTableWidget(centralWidget);
        resultTable->setObjectName(QStringLiteral("resultTable"));
        resultTable->setEnabled(true);
        resultTable->setGeometry(QRect(480, 20, 431, 431));
        resultTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        resultTable->setSortingEnabled(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 200, 461, 261));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        chartButton = new QPushButton(tab);
        chartButton->setObjectName(QStringLiteral("chartButton"));
        chartButton->setGeometry(QRect(350, 20, 101, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MyFiles/110955-data/png/lifeline-turning-into-directional-arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        chartButton->setIcon(icon);
        chartButton->setIconSize(QSize(25, 25));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 337, 58));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout);

        allTablesasdasd = new QComboBox(layoutWidget);
        allTablesasdasd->setObjectName(QStringLiteral("allTablesasdasd"));

        verticalLayout_5->addWidget(allTablesasdasd);


        horizontalLayout_4->addLayout(verticalLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        addRecordButton = new QPushButton(layoutWidget);
        addRecordButton->setObjectName(QStringLiteral("addRecordButton"));
        addRecordButton->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MyFiles/110955-data/png/bible-with-cross-symbol-variant.png"), QSize(), QIcon::Normal, QIcon::Off);
        addRecordButton->setIcon(icon1);

        gridLayout->addWidget(addRecordButton, 0, 0, 1, 1);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MyFiles/110955-data/png/data-storage-drive-with-cross-mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);

        gridLayout->addWidget(deleteButton, 1, 0, 1, 1);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MyFiles/110955-data/png/data-storage.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon3);

        gridLayout->addWidget(saveButton, 1, 1, 1, 1);

        editModeButton = new QPushButton(layoutWidget);
        editModeButton->setObjectName(QStringLiteral("editModeButton"));
        editModeButton->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MyFiles/110955-data/png/data-storage-disc.png"), QSize(), QIcon::Normal, QIcon::Off);
        editModeButton->setIcon(icon4);

        gridLayout->addWidget(editModeButton, 0, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 90, 421, 118));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        searchTypeField = new QComboBox(layoutWidget1);
        searchTypeField->setObjectName(QStringLiteral("searchTypeField"));
        searchTypeField->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(searchTypeField);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        searchFieldsLayout = new QHBoxLayout();
        searchFieldsLayout->setSpacing(6);
        searchFieldsLayout->setObjectName(QStringLiteral("searchFieldsLayout"));
        searchLineEdit = new QLineEdit(layoutWidget1);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));

        searchFieldsLayout->addWidget(searchLineEdit);

        searchOptionBox = new QComboBox(layoutWidget1);
        searchOptionBox->setObjectName(QStringLiteral("searchOptionBox"));

        searchFieldsLayout->addWidget(searchOptionBox);

        searchLineEdit_2 = new QLineEdit(layoutWidget1);
        searchLineEdit_2->setObjectName(QStringLiteral("searchLineEdit_2"));

        searchFieldsLayout->addWidget(searchLineEdit_2);


        verticalLayout_3->addLayout(searchFieldsLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        columnForSearch = new QComboBox(layoutWidget1);
        columnForSearch->setObjectName(QStringLiteral("columnForSearch"));
        columnForSearch->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(columnForSearch);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        searchButton = new QPushButton(layoutWidget1);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        QFont font;
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        searchButton->setFont(font);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MyFiles/110955-data/png/data-search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon5);

        horizontalLayout_6->addWidget(searchButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_6->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        loginGroupBox = new QGroupBox(tab_2);
        loginGroupBox->setObjectName(QStringLiteral("loginGroupBox"));
        loginGroupBox->setGeometry(QRect(10, 10, 207, 151));
        verticalLayout_2 = new QVBoxLayout(loginGroupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(loginGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(loginGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        usernameLineEdit = new QLineEdit(loginGroupBox);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));

        gridLayout_2->addWidget(usernameLineEdit, 1, 1, 1, 1);

        passwordLineEdit = new QLineEdit(loginGroupBox);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(passwordLineEdit, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        signInButton = new QPushButton(loginGroupBox);
        signInButton->setObjectName(QStringLiteral("signInButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/MyFiles/110955-data/png/interface.png"), QSize(), QIcon::Normal, QIcon::Off);
        signInButton->setIcon(icon6);

        verticalLayout_2->addWidget(signInButton);

        advancedOptions = new QGroupBox(tab_2);
        advancedOptions->setObjectName(QStringLiteral("advancedOptions"));
        advancedOptions->setEnabled(true);
        advancedOptions->setGeometry(QRect(230, 10, 201, 151));
        layoutWidget2 = new QWidget(advancedOptions);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 181, 121));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        queryEditor = new QPlainTextEdit(layoutWidget2);
        queryEditor->setObjectName(QStringLiteral("queryEditor"));
        queryEditor->setEnabled(true);

        verticalLayout_4->addWidget(queryEditor);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        executeQueryButton = new QPushButton(layoutWidget2);
        executeQueryButton->setObjectName(QStringLiteral("executeQueryButton"));
        executeQueryButton->setEnabled(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/MyFiles/110955-data/png/database-edition.png"), QSize(), QIcon::Normal, QIcon::Off);
        executeQueryButton->setIcon(icon7);

        verticalLayout_4->addWidget(executeQueryButton);

        tabWidget->addTab(tab_2, QString());
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 211, 191));
        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 197, 161));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        connectButton = new QPushButton(layoutWidget3);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/MyFiles/110955-data/png/folder-silhouette-with-arrow-pointing-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        connectButton->setIcon(icon8);
        connectButton->setFlat(false);

        verticalLayout->addWidget(connectButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        connectionIndicator = new QCheckBox(layoutWidget3);
        connectionIndicator->setObjectName(QStringLiteral("connectionIndicator"));
        connectionIndicator->setEnabled(true);
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

        disconnectButton = new QPushButton(layoutWidget3);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));
        disconnectButton->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/MyFiles/110955-data/png/folder-with-close-or-delete-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        disconnectButton->setIcon(icon9);

        verticalLayout->addWidget(disconnectButton);

        exitButton = new QPushButton(layoutWidget3);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setAutoFillBackground(false);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/MyFiles/110955-data/png/direction.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitButton->setIcon(icon10);

        verticalLayout->addWidget(exitButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 935, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        chartButton->setText(QApplication::translate("MainWindow", "Wykres", 0));
        label->setText(QApplication::translate("MainWindow", "Available tables", 0));
        addRecordButton->setText(QApplication::translate("MainWindow", "Add record", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete record", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        editModeButton->setText(QApplication::translate("MainWindow", "Edit mode", 0));
        label_5->setText(QApplication::translate("MainWindow", "Query type:", 0));
        searchTypeField->clear();
        searchTypeField->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "simple", 0)
         << QApplication::translate("MainWindow", "mathematical", 0)
         << QApplication::translate("MainWindow", "logical", 0)
        );
        searchLineEdit->setText(QString());
        searchLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "(eg. Krak\303\263w)", 0));
        searchOptionBox->clear();
        searchOptionBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Druga", 0)
         << QApplication::translate("MainWindow", "Dupa", 0)
        );
        searchLineEdit_2->setText(QString());
        searchLineEdit_2->setPlaceholderText(QString());
        label_8->setText(QApplication::translate("MainWindow", "in column", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Clear", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Modify", 0));
        loginGroupBox->setTitle(QApplication::translate("MainWindow", "Login", 0));
        label_4->setText(QApplication::translate("MainWindow", "Password", 0));
        label_2->setText(QApplication::translate("MainWindow", "User name", 0));
        usernameLineEdit->setText(QApplication::translate("MainWindow", "user", 0));
        passwordLineEdit->setText(QString());
        signInButton->setText(QApplication::translate("MainWindow", "Sign in", 0));
        advancedOptions->setTitle(QApplication::translate("MainWindow", "Advanced options", 0));
        queryEditor->setPlainText(QApplication::translate("MainWindow", "SELECT * from overall_performance", 0));
        executeQueryButton->setText(QApplication::translate("MainWindow", "Execute custom query", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Login", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Connection", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect to Database", 0));
        connectionIndicator->setText(QApplication::translate("MainWindow", "Connection state", 0));
        disconnectButton->setText(QApplication::translate("MainWindow", "Disconnect from Database", 0));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
