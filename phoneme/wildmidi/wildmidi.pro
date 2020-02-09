TEMPLATE	= lib
VERSION		= 0.2.2
TARGET      = wildmidi

CONFIG		+= staticlib
QT -= core gui
OBJECTS_DIR = ../build/$${TARGET}/.obj
DESTDIR 	= ../build


HEADERS += \
config.h \
wildmidi_lib.h

SOURCES += \
wildmidi_lib.c
