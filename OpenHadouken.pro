TEMPLATE = app
TARGET = hadouken
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++11

SOURCES += main.cpp \
    src/game.cpp \
    src/keyboard.cpp \
    src/hadouken.cpp

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    src/headers/game.h \
    src/headers/keyboard.h \
    src/headers/hadouken.h

