#-------------------------------------------------
#
# Project created by QtCreator 2015-10-26T09:56:32
#
#-------------------------------------------------

QT       += core gui
QT        += sql
QT       += xml
QT       += serialport
QT     += QwtSvg
TARGET = xl902
TEMPLATE = app


SOURCES += main.cpp \
    mainwidget.cpp \
    SerialPort/win_qextserialport.cpp \
    SerialPort/qextserialport.cpp \
    SerialPort/qextserialbase.cpp \
    SerialPort/ManageSerialPort.cpp \
    SerialPort/serPort_Page.cpp \
    thread/thread_fun.cpp \
    thread/thread_init.cpp \
    SMV/RSMV/RSMV_option.cpp \
    SMV/RSMV/RSMV_wave.cpp \
    SMV/RSMV/RSMV_harmonic.cpp \
    elapseTime.cpp \
    SMV/RSMV/RSMV_init_Harmonic.cpp \
    sysIni.cpp \
    rightSideBar.cpp \
    driver_xl618_2.cpp \
    driver_xl618_1.cpp \
    form/buildWord.cpp \
    form/form_Page.cpp \
    RD_update.cpp \
    SMV/RSMV/ME_update.cpp \
    SMV/RSMV/ES_update.cpp \
    RS_charger.cpp \
    SP.cpp

HEADERS  += \
    mainwidget.h \
    stdafx.h \
    xl618.h \
    SerialPort/win_qextserialport.h \
    SerialPort/qextserialport.h \
    SerialPort/qextserialbase.h \
    SerialPort/ManageSerialPort.h \
    thread/timeThread.h \
    SMV/RSMV/RSMV_initHarmonic.h

FORMS    += \
    mainwidget.ui

RESOURCES += \
    pic.qrc \

INCLUDEPATH +="D:/software/Qwt-6.0.2_485/include"

LIBS+=-L "D:/software/Qwt-6.0.2_485/lib" -lqwt

CONFIG+=qaxcontainer
