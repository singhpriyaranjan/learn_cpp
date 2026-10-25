TEMPLATE = app
TARGET = disjoint_sets
QT -= gui
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    Examples.cpp

HEADERS += \
    Examples.h