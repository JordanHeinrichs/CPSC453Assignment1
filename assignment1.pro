######################################################################
# Automatically generated by qmake (3.0) Tue Sep 15 12:00:14 2015
######################################################################

QT+=widgets
TARGET = ../release/assignment1
TEMPLATE = app
INCLUDEPATH += .

QMAKE_CXXFLAGS += -Wall -Werror
RCC_DIR= ../release
DESTDIR = ../release
OBJECTS_DIR = ../release/.obj
MOC_DIR = ../release/.moc
RCC_DIR = ../release/.rcc
UI_DIR = ../release/.ui

shaders.path = ../release/
shaders.files = per-fragment-phong*

INSTALLS += shaders

# Input
HEADERS += \
    game.h \
    GameTickerService.h \
    I_Game.h \
    I_GameTickerService.h \
    I_WindowUi.h \
    renderer.h \
    window.h \
    WindowUi.h \
    WindowView.h

SOURCES += \
    game.cpp \
    GameTickerService.cpp \
    main.cpp \
    renderer.cpp \
    window.cpp \
    WindowUi.cpp \
    WindowView.cpp
