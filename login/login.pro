#-------------------------------------------------
#
# Project created by QtCreator 2018-07-20T23:01:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    mynotepad.cpp \
    myevent.cpp \
    mytimer.cpp \
    mypainter.cpp \
    myform.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    mynotepad.h \
    myevent.h \
    mytimer.h \
    mypainter.h \
    myform.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    mynotepad.ui \
    myevent.ui \
    mytimer.ui \
    mypainter.ui \
    myform.ui
