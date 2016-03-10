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
    elapseTime.cpp \
    sysIni.cpp \
    form/save_doc.cpp \
    form/edit_form.cpp \
    ripple/ripple.cpp \
    testPower/ME_update.cpp \
    testPower/ES_update.cpp \
    testPower/RD_update.cpp \
    sideBar_right.cpp \
    testPower/ES_wave.cpp \
    testPower/testPower_page.cpp \
    interface_xl618_1.cpp \
    interface_xl618_2.cpp \
    testPower/set_parameter.cpp \
    testPower/read_BMS.cpp

HEADERS  += \
    mainwidget.h \
    stdafx.h \
    xl618.h \
    SerialPort/win_qextserialport.h \
    SerialPort/qextserialport.h \
    SerialPort/qextserialbase.h \
    SerialPort/ManageSerialPort.h \
    thread/timeThread.h \
    testPower/RSMV_option.h

FORMS    += \
    mainwidget.ui

RESOURCES += \
    pic.qrc \

INCLUDEPATH +="D:/software/Qwt-6.0.2_485/include"

LIBS+=-L "D:/software/Qwt-6.0.2_485/lib" -lqwt

CONFIG+=qaxcontainer
