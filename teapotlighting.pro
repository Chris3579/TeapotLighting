QT += core gui widgets opengl
QT += opengl
QT += core gui opengl
QT += openglwidgets

TARGET = TeapotLighting
TEMPLATE = app

SOURCES += main.cpp\
           mainwindow.cpp\
           teapotwidget.cpp

HEADERS  += mainwindow.h\
            teapotwidget.h

FORMS    += mainwindow.ui

LIBS += -lGL -lGLU -lglut
