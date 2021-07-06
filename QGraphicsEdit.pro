#-------------------------------------------------
#
# Project created by QtCreator 2018-04-16T15:31:46
#
#-------------------------------------------------

QT       += core gui svg xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QGraphicsEdit
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    rectangle.cpp \
    workplace.cpp \
    line.cpp \
    svssave.cpp \
    colorlabel.cpp \
    dotsignal.cpp \
    diagramitem.cpp \
    ellipse.cpp

HEADERS += \
        mainwindow.h \
    colorlabel.h \
    dotsignal.h \
    workplace.h \
    dotsignal.h \
    line.h \
    rectangle.h \
    svssave.h \
    diagramitem.h \
    ellipse.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    Resources/cube.svg \
    Resources/paint-palette.svg \
    Resources/pen.svg \
    Resources/square.svg \
    Resources/vector.svg
