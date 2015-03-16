#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T23:28:48
#
#-------------------------------------------------

QT += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tuner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    audiostream.cpp

HEADERS  += mainwindow.h \
    audiostream.h

FORMS    += mainwindow.ui
