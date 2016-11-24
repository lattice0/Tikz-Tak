TEMPLATE = app
TARGET = Tikz-Tak

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    windowaddcal.cpp \
    aboutx.cpp \
    about.cpp

HEADERS += \
    mainwindow.h \
    windowaddcal.h \
    aboutx.h \
    about.h

DISTFILES +=

FORMS += \
    mainwindow.ui \
    windowaddcal.ui \
    aboutx.ui \
    about.ui

RESOURCES = images.qrc

LIBS += -L/usr/lib/nvidia-361
