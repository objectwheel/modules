TEMPLATE = lib
CONFIG  += plugin c++14 strict_c strict_c++ utf8_source hide_symbols skip_target_version_ext
TARGET   = objectwheelmodule
DESTDIR  = ../Modules/Objectwheel
QT      += qml
gcc:QMAKE_CXXFLAGS += -pedantic-errors
msvc:QMAKE_CXXFLAGS += -permissive-
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

OW_MODULE_VERSION_MAJOR = 1
OW_MODULE_VERSION_MINOR = 0

DEFINES += OW_MODULE_VERSION_MAJOR=$$OW_MODULE_VERSION_MAJOR \
           OW_MODULE_VERSION_MINOR=$$OW_MODULE_VERSION_MINOR
VERSION  = $${OW_MODULE_VERSION_MAJOR}.$${OW_MODULE_VERSION_MINOR}

INCLUDEPATH += $$PWD

HEADERS += $$PWD/objectwheel.h \
           $$PWD/translation.h

SOURCES += $$PWD/objectwheelmodule.cpp \
           $$PWD/objectwheel.cpp \
           $$PWD/translation.cpp

OTHER_FILES += $$PWD/qmldir

include($$PWD/../modules.pri)
