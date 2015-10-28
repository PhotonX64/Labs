#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T18:33:03
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    itemclient.cpp \
    dlgconnect.cpp

HEADERS  += mainwindow.h \
    itemclient.h \
    dlgconnect.h

FORMS    += mainwindow.ui \
    dlgconnect.ui
