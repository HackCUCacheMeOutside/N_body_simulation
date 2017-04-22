#-------------------------------------------------
#
# Project created by QtCreator 2017-04-22T13:00:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FreeBodySimulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    body.cpp \
    system.cpp

HEADERS  += mainwindow.hpp \
    body.hpp \
    system.hpp

FORMS    += mainwindow.ui
