TEMPLATE	= lib
VERSION		= 1.01e
TARGET		= minizip

CONFIG		+= staticlib
QT -= core gui
OBJECTS_DIR = ../build/$${TARGET}/.obj
DESTDIR 	= ../build

DEFINES += \
NOUNCRYPT
#_ZLIBIOAPI_H
PKGCONFIG += zlib

#QMAKE_DISTCLEAN += ${DESTDIR}/${TARGET}

HEADERS 	= \
unzip.h \
ioapi.h

SOURCES 	= \
unzip.c \
ioapi.c
