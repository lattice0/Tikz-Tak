TEMPLATE = app
TARGET = TikZ-TaK
CONFIG += c++11

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    windowaddcal.cpp \
    aboutx.cpp \

HEADERS += \
    mainwindow.h \
    windowaddcal.h \
    aboutx.h \


FORMS += \
    mainwindow.ui \
    windowaddcal.ui \
    aboutx.ui \

RESOURCES = images.qrc

TRANSLATIONS = tikz-tak_en.ts

LIBS += -L/usr/lib/nvidia-361
