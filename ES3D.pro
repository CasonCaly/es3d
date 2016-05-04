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
    ESGLView.cpp \
    ESProgram.cpp \
    ESBuffer.cpp \
    ESUniform.cpp \
    ESAttribute.cpp

HEADERS  += MainWindow.h \
    ESGLView.h \
    ESProgram.h \
    ESBuffer.h \
    ESUniform.h \
    ESAttribute.h

FORMS    += mainwindow.ui
