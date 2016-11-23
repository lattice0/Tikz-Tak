TEMPLATE = app
TARGET = Tikz-Tak

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    windowaddcal.cpp

HEADERS += \
    mainwindow.h \
    windowaddcal.h

DISTFILES +=

FORMS += \
    mainwindow.ui \
    windowaddcal.ui

RESOURCES = images.qrc
