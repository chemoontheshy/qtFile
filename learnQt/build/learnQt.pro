# -------------------------------------------------
# Project created by QtCreator 2022-06-28T14:42:58
# -------------------------------------------------
#module
QT += network \
    sql \
    xml
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = learnQt
TEMPLATE = app
SOURCES += ../src/main.cpp \
    ../src/mainwindow.cpp \
    ../src/test.cpp
HEADERS += ../src/mainwindow.h \
    ../src/test.h \
    ../src/singleton.h
FORMS += ../src/mainwindow.ui

# Éú³ÉexeÂ·¾¶
CONFIG += debug_and_release
CONFIG(debug,debug|release)
{
    DESTDIR = ../bin/Debug
}
