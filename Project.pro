QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CLEAN += test tree .qmake.stash

tree {
  TARGET = tree
  HEADERS += TreeView.hpp Tree.hpp Node.hpp Heap.hpp Iterator.hpp Complex.hpp
  SOURCES += main.cpp TreeView.cpp
}

test {
  TARGET = test
  HEADERS += Tree.hpp Node.hpp Heap.hpp Iterator.hpp
  SOURCES += Test.cpp TestCounter.cpp
}
