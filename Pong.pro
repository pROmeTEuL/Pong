TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

SOURCES += \
        bat.cpp \
        main.cpp

DISTFILES += \
    fonts/DS-DIGI.TTF

HEADERS += \
    bat.h
