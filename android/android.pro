TEMPLATE = lib
CONFIG  += plugin c++14 strict_c strict_c++ utf8_source hide_symbols skip_target_version_ext
TARGET   = androidmodule
DESTDIR  = ../Modules/Objectwheel/Android
QT      += qml
android:QT += androidextras
gcc:QMAKE_CXXFLAGS += -pedantic-errors
msvc:QMAKE_CXXFLAGS += -permissive-
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

OW_MODULE_VERSION_MAJOR = 1
OW_MODULE_VERSION_MINOR = 0

DEFINES += OW_MODULE_VERSION_MAJOR=$$OW_MODULE_VERSION_MAJOR \
           OW_MODULE_VERSION_MINOR=$$OW_MODULE_VERSION_MINOR
VERSION  = $${OW_MODULE_VERSION_MAJOR}.$${OW_MODULE_VERSION_MINOR}

INCLUDEPATH += $$PWD

HEADERS += $$PWD/android.h

SOURCES += $$PWD/androidmodule.cpp \
           $$PWD/android.cpp

OTHER_FILES += $$PWD/qmldir

include($$PWD/../modules.pri)
