TEMPLATE = app
TARGET = problems
QT -= gui
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    Examples.cpp \
    solutions.cpp

HEADERS += \
    Examples.h \
    Solutions.h