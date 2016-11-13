TEMPLATE = app
TARGET = Tikz-Tak

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

DISTFILES +=

FORMS += \
    mainwindow.ui
