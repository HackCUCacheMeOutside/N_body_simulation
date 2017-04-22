#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T13:00:35
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FreeBodySimulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    body.cpp \
    system.cpp \
    bodygraphicsitem.cpp

HEADERS  += mainwindow.hpp \
    body.hpp \
    system.hpp \
    bodygraphicsitem.hpp

FORMS    += mainwindow.ui
