TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

SOURCES += \
        ball.cpp \
        bat.cpp \
        main.cpp

DISTFILES += \
    fonts/DS-DIGI.TTF \
    sounds/JosCol.wav \
    sounds/Rip.wav \
    sounds/SusCol.wav \
    sounds/ZidCol.wav

HEADERS += \
    ball.h \
    bat.h
