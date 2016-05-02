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
    ESGLView.cpp

HEADERS  += MainWindow.h \
    ESGLView.h

FORMS    += mainwindow.ui
