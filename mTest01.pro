QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += debug_and_release

TARGET = mTest01
TEMPLATE = app

TRANSLATIONS = main_uk.ts

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    numbers123.cpp \
    myqlineedit.cpp

HEADERS += \
        mainwindow.h \
    numbers123.h \
    myqlineedit.h

RESOURCES += \
    translations.qrc
