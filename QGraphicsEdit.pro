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
    colorlabel.cpp \
    rectangle.cpp \
    dotsignal.cpp \
    workplace.cpp \
    selectionrect.cpp \
    diagramitem.cpp \
    line.cpp \
    svssave.cpp \
    colorlabel.cpp \
    diagramitem.cpp \
    dotsignal.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    selectionrect.cpp \
    svssave.cpp \
    workplace.cpp

HEADERS += \
        mainwindow.h \
    colorlabel.h \
    rectangle.h \
    dotsignal.h \
    workplace.h \
    selectionrect.h \
    diagramitem.h \
    line.h \
    svssave.h \
    colorlabel.h \
    diagramitem.h \
    dotsignal.h \
    line.h \
    mainwindow.h \
    rectangle.h \
    selectionrect.h \
    svssave.h \
    workplace.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    Resources/grid-background.jpg \
    Resources/cube.svg \
    Resources/paint-palette.svg \
    Resources/pen.svg \
    Resources/square.svg \
    Resources/vector.svg
