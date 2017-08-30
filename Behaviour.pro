#-------------------------------------------------
#
# Project created by QtCreator 2017-07-28T10:04:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Behaviour
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    CameraGet.cpp \
    PreProcess.cpp \
    FrameDif.cpp

HEADERS  += widget.h \
    CameraGet.h \
    COMDEF.h \
    PreProcess.h \
    FrameDif.h

FORMS    += widget.ui

DISTFILES += \
    README.md

INCLUDEPATH += D:\OpenCV\install\include

LIBS += -LD:\OpenCV\install\bin -llibopencv_core231 -llibopencv_highgui231 -llibopencv_imgproc231

