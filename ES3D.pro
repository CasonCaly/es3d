#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T15:45:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl
TARGET = ES3D
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    core/ESAttribute.cpp \
    core/ESBuffer.cpp \
    core/ESGLView.cpp \
    core/ESProgram.cpp \
    core/ESUniform.cpp \
    core/ESExample.cpp \
    example/ESHelloArrow.cpp

HEADERS  += MainWindow.h \
    core/ESAttribute.h \
    core/ESBuffer.h \
    core/ESGLView.h \
    core/ESProgram.h \
    core/ESUniform.h \
    core/ESExample.h \
    example/ESHelloArrow.h

FORMS    += mainwindow.ui
