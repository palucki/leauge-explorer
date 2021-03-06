#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T11:59:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = LeaugeExplorer
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    DatabaseHandler.cpp \
    MainWindow.cpp \
    AddRecordHelper.cpp \
    loginhelper.cpp \
    simplesearch.cpp \
    logger.cpp \
    qcustomplot.cpp \
    plotter.cpp \
    mathsearch.cpp \
    logicalsearch.cpp \
    digitalclock.cpp \
    searchtype.cpp \
    tableexporter.cpp

HEADERS  += \
    DatabaseHandler.h \
    MainWindow.h \
    AddRecordHelper.h \
    loginhelper.h \
    searchtype.h \
    simplesearch.h \
    foundrecord.h \
    logger.h \
    qcustomplot.h \
    plotter.h \
    mathsearch.h \
    logicalsearch.h \
    digitalclock.h \
    tableexporter.h
FORMS    += mainwindow.ui \
    addrecordhelper.ui \
    plotter.ui

RESOURCES += \
    myresources.qrc

DISTFILES += \
    to_do
