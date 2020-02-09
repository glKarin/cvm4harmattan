TARGET      = cvm
HEADERS     += framebuffer.h cvmthread.h locationwidget.h main.h
SOURCES     += framebuffer.cpp cvmthread.cpp locationwidget.cpp main.cpp
FORMS       += #UIS#
LEXSOURCES  += #LEXS#
YACCSOURCES += #YACCS#

INCLUDEPATH += .. . harm
LIBS        += -Wl,-rpath,/opt/phoneme/bin -L../bin -lcvm
DEFINES     += _HARMATTAN
PKGCONFIG += maliit-1.0 meegotouchcore
INCLUDEPATH += harm
HEADERS += \
cvm.h \
mediaplayer.h \
defs.h \
harm/macros.h \
harm/vkblayout.h \
harm/t9scheme.h \
harm/vkbscheme.h \
harm/softbutton.h \
harm/button.h \
harm/toolicon.h \
harm/vkblayer.h \
harm/settingwidget.h \
harm/graphicswidget.h

SOURCES += \
cvm.cpp \
mediaplayer.cpp \
harm/vkblayout.cpp \
harm/t9scheme.cpp \
harm/vkbscheme.cpp \
harm/softbutton.cpp \
harm/button.cpp \
harm/toolicon.cpp \
harm/vkblayer.cpp \
harm/settingwidget.cpp \
harm/graphicswidget.cpp

PRE_TARGETDEPS += \
../build/libminizip.a \
../build/libwildmidi.a

LIBS            += -L../build ../build/libminizip.a ../build/libwildmidi.a

include(../common/common.pri)

CONFIG      += link_pkgconfig
#PKGCONFIG   += liblocation

CONFIG      += mobility
MOBILITY     = location

QMAKE_CXXFLAGS    += -rdynamic

# All generated files goes to the same directory
OBJECTS_DIR = ../build/$${TARGET}/.obj
MOC_DIR     = ../build/$${TARGET}/.moc
RCC_DIR     = ../build/$${TARGET}/.rcc
UI_DIR      = ../build/$${TARGET}/.ui

DESTDIR     = ../bin
TEMPLATE    = app
DEPENDPATH  +=
VPATH       += #src uis
CONFIG      -= 
#k CONFIG      += debug
QT          = core gui declarative #phonon

DEFINES += _DEBUG
#DEFINES += _MEDIAPLAYER_BACKEND_USING_QTMOBILITY
DEFINES += _MEDIAPLAYER_BACKEND_USING_SDL

contains(DEFINES, _MEDIAPLAYER_BACKEND_USING_PHONON) {
	Qt += phonon
} else:contains(DEFINES, _MEDIAPLAYER_BACKEND_USING_SDL) {
	LIBS += -lSDL -lSDL_mixer
} else:contains(DEFINES, _MEDIAPLAYER_BACKEND_USING_QTMOBILITY) {
# do not link OpenGLESv2
	#MOBILITY    += multimedia
	LIBS += -L/usr/lib -lQtMultimediaKit -lQtNetwork -lpthread #-lpulse
	INCLUDEPATH += /usr/include/qt4/QtMultimediaKit
}

INSTALLS    += target
target.path  = /opt/phoneme/bin

INSTALLS      += desktop
desktop.path   = /usr/share/applications/hildon
desktop.files  = data/runmidlet.desktop
desktop.files += data/midlet.desktop
desktop.files += data/midletsettings.desktop

INSTALLS   += package
package.path   = /usr/share/mime/packages
package.files  = data/midlet.xml

INSTALLS       += desktop_n9
desktop_n9.path   = /usr/share/applications
desktop_n9.files  = data/runmidlet.desktop
desktop_n9.files += data/midlet.desktop
desktop_n9.files += data/midletsettings.desktop

INSTALLS      += service
service.path   = /usr/share/dbus-1/services
service.files  = data/midlet.service

INSTALLS     += icon
icon.path   = /usr/share/icons/hicolor/64x64/apps
icon.files  = data/64x64/duke.png

INSTALLS     += mimetypes
mimetypes.path   = /usr/share/icons/hicolor/64x64/mimetypes
mimetypes.files  = data/64x64/application-java-archive.png
mimetypes.files += data/64x64/application-x-java-archive.png
mimetypes.files += data/64x64/text-vnd.sun.j2me.app-descriptor.png

INSTALLS     += icon_n9
icon_n9.path   = /usr/share/themes/blanco/meegotouch/icons
icon_n9.files  = data/64x64/duke.png

INSTALLS     += bin
bin.path   = /opt/phoneme/bin
bin.files  = ../runmidlet/build/runmidlet
bin.files += ../midletservice/build/midletservice
bin.files += ../settings/build/settings

INSTALLS     += lib
lib.path   = /opt/phoneme/bin
lib.files  = ../../bin/libcvm.so

INSTALLS      += phoneme
phoneme.path   = /opt/phoneme
phoneme.files += ../excalibur.sh
phoneme.files += ../../legal
phoneme.files += ../../lib
phoneme.files += ../../midp
phoneme.files += ../../*.jar
phoneme.files += ../../*.zip
phoneme.files += ../../*.sh

#
# Targets for debian source and binary package creation
#
debian-src.commands = dpkg-buildpackage -S -r -us -uc -d
debian-bin.commands = dpkg-buildpackage -b -r -uc -d
debian-all.depends = debian-src debian-bin

#
# Clean all but Makefile
#
compiler_clean.commands = -$(DEL_FILE) $(TARGET)

QMAKE_EXTRA_TARGETS += debian-all debian-src debian-bin compiler_clean
