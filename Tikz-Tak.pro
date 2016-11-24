TEMPLATE = app
TARGET = TikZ-TaK

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

DISTFILES += \
    translations/tikz-tak_en.qm \
    translations/tikz-tak_en.ts

FORMS += \
    mainwindow.ui \
    windowaddcal.ui \
    aboutx.ui \
    about.ui

RESOURCES = images.qrc

TRANSLATIONS = tikz-tak_en.ts

LIBS += -L/usr/lib/nvidia-361
