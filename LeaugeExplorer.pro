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
    MainWindow.cpp

HEADERS  += \
    DatabaseHandler.h \
    MainWindow.h

FORMS    += mainwindow.ui
