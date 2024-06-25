QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += Tree.hpp Node.hpp Heap.hpp Iterator.hpp
SOURCES += Test.cpp TestCounter.cpp

# Define a custom target to run the program with `make test`
test.target = test
test.depends = first # Depend on the first build target, ensuring the program is built before running

# Add the test executable to the clean files
QMAKE_CLEAN += tree test .qmake.stash