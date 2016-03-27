#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T11:59:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LeaugeExplorer
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    DatabaseHandler.cpp \
    MainWindow.cpp \
    AddRecordHelper.cpp \
    loginhelper.cpp \
    simplesearch.cpp \
    logger.cpp

HEADERS  += \
    DatabaseHandler.h \
    MainWindow.h \
    AddRecordHelper.h \
    loginhelper.h \
    searchtype.h \
    simplesearch.h \
    foundrecord.h \
    logger.h
FORMS    += mainwindow.ui \
    addrecordhelper.ui

RESOURCES += \
    myresources.qrc
