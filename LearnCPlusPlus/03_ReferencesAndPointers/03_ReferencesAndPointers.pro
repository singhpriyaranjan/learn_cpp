TEMPLATE = app
TARGET = 03_ReferencesAndPointers
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += $$files($$PWD/*.cpp)
HEADERS += $$files($$PWD/*.h)
INCLUDEPATH += $$PWD