TEMPLATE = lib
CONFIG  += plugin c++14 strict_c++
TARGET   = androidmodule
DESTDIR  = ../Modules/Objectwheel/Android
QT      += qml
android:QT += androidextras
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
unix:QMAKE_CXXFLAGS += -pedantic-errors

OW_MODULE_VERSION_MAJOR = 1
OW_MODULE_VERSION_MINOR = 0

DEFINES += OW_MODULE_VERSION_MAJOR=$$OW_MODULE_VERSION_MAJOR \
           OW_MODULE_VERSION_MINOR=$$OW_MODULE_VERSION_MINOR
VERSION  = $${OW_MODULE_VERSION_MAJOR}.$${OW_MODULE_VERSION_MINOR}

INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD

HEADERS += $$PWD/android.h

SOURCES += $$PWD/androidmodule.cpp \
           $$PWD/android.cpp

OTHER_FILES += $$PWD/qmldir

include($$PWD/../modules.pri)
