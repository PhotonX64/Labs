#-------------------------------------------------
#
# Project created by QtCreator 2015-09-11T11:22:22
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestCreator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datebaseedit.cpp \
    dlgtest.cpp \
    dlgaddtest.cpp

HEADERS  += mainwindow.h \
    datebaseedit.h \
    dlgtest.h \
    dlgaddtest.h

FORMS    += mainwindow.ui \
    dlgtest.ui \
    dlgaddtest.ui
