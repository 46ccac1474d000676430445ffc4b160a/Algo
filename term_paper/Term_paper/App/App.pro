# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

QT += core gui widgets

TARGET = App
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR = ../../Build

HEADERS = \
   $$PWD/Trie/trie.hpp \
   $$PWD/mainwindow.hpp \
    TextEdit/textedit.hpp

SOURCES = \
   $$PWD/Trie/trie.cpp \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp \
    TextEdit/textedit.cpp

FORMS = \
    $$PWD/mainwindow.ui

INCLUDEPATH =

#DEFINES = 

