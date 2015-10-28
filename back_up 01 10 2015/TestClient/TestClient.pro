#-------------------------------------------------
#
# Project created by QtCreator 2015-09-10T11:59:12
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dlgconnecttoserver.cpp \
    datebaseloader.cpp \
    quest.cpp \
    varanswer.cpp \
    test.cpp \
    dlgtest.cpp \
    widgtest.cpp \
    dlgchoisetest.cpp

HEADERS  += mainwindow.h \
    dlgconnecttoserver.h \
    datebaseloader.h \
    quest.h \
    varanswer.h \
    test.h \
    dlgtest.h \
    widgtest.h \
    dlgchoisetest.h

FORMS    += mainwindow.ui \
    dlgconnecttoserver.ui \
    dlgtest.ui \
    widgtest.ui \
    dlgchoisetest.ui

RESOURCES += \
    res.qrc
