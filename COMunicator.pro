#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T18:49:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMunicator
TEMPLATE = app
CONFIG += C++11


SOURCES += main.cpp\
        mainwindow.cpp \
    comhandle.cpp \
    messagegetter.cpp \
    messagesender.cpp \
    comoperator.cpp

HEADERS  += mainwindow.h \
    comhandle.h \
    messagegetter.h \
    messagesender.h \
    comoperator.h

FORMS    += mainwindow.ui
