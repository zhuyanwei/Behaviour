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
    FrameDif.cpp \
    ClassHistogram.cpp \
    BackDif.cpp \
    ForegroundExtraction.cpp \
    bgfg_vibe.cpp \
    PBAS.cpp

HEADERS  += widget.h \
    CameraGet.h \
    COMDEF.h \
    PreProcess.h \
    FrameDif.h \
    ClassHistogram.h \
    BackDif.h \
    ForegroundExtraction.h \
    bgfg_vibe.hpp \
    PBAS.h

FORMS    += widget.ui

DISTFILES += \
    README.md

INCLUDEPATH += D:\OpenCV\install\include

LIBS += -LD:\OpenCV\install\bin -llibopencv_core231 -llibopencv_highgui231 -llibopencv_imgproc231 -llibopencv_video231

