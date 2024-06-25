QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tree

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += TreeView.hpp Tree.hpp Node.hpp Heap.hpp Iterator.hpp Complex.hpp
SOURCES += main.cpp TreeView.cpp

# Define a custom target to run the program with `make tree`
tree.target = tree
tree.depends = first # Depend on the first build target, ensuring the program is built before running

# Add the tree executable to the clean files
QMAKE_CLEAN += tree .qmake.stash