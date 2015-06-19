#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T20:50:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = modbus
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/modbus-rtu.c \
    src/modbus.c \
    src/modbus-data.c \
    modbus-wangwei.cpp

HEADERS  += mainwindow.h \
    modbus-private.h \
    modbus-rtu.h \
    modbus-version.h \
    modbus.h \
    config.h \
    modbus-wangwei.h

FORMS    += mainwindow.ui
