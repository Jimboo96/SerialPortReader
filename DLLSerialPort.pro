#-------------------------------------------------
#
# Project created by QtCreator 2017-04-24T13:46:22
#
#-------------------------------------------------

QT       -= gui
QT       += serialport

TARGET = DLLSerialPort
TEMPLATE = lib

DEFINES += DLLSERIALPORT_LIBRARY

SOURCES += dllserialport.cpp

HEADERS += dllserialport.h\
        dllserialport_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
