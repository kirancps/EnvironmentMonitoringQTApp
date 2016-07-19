#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T17:02:55
#
#-------------------------------------------------

QT       += core gui serialport multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialCommunication
TEMPLATE = app


SOURCES += main.cpp\
        serialcomm.cpp

HEADERS  += serialcomm.h

FORMS    += serialcomm.ui
