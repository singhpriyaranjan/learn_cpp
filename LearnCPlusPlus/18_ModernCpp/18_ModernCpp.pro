TEMPLATE = app
TARGET = 18_ModernCpp
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += $$files($$PWD/*.cpp)
HEADERS += $$files($$PWD/*.h)
INCLUDEPATH += $$PWD