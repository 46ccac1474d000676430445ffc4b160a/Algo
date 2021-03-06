# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

QT += core gui widgets

TARGET = App
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

win32:DESTDIR = ../../Build-Win

win32:RC_ICONS = icon.ico

HEADERS = \
   $$PWD/Trie/trie.hpp \
   $$PWD/mainwindow.hpp \
    TextEdit/textedit.hpp \
    TextEdit/suggestionslist.hpp \
    TextEdit/textedit_p.hpp

SOURCES = \
   $$PWD/Trie/trie.cpp \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp \
    TextEdit/textedit.cpp \
    TextEdit/suggestionslist.cpp \
    TextEdit/textedit_p.cpp

FORMS = \
    mainwindow.ui

RESOURCES += \
    rec.qrc

