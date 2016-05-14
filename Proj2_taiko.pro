#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T21:05:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proj2_taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    taikopage.cpp \
    key.cpp

HEADERS  += mainwindow.h \
    taikopage.h \
    key.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc
