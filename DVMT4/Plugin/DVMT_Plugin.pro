QT += widgets

TEMPLATE = lib
DEFINES += DVMT_PLUGIN_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cvvcsymbol.cpp \
    dvmt_plugin.cpp \
    plugindialog.cpp \
    project.cpp

HEADERS += \
    DVMT_Plugin_global.h \
    cvvcsymbol.h \
    dvmt_plugin.h \
    plugindialog.h \
    project.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    plugindialog.ui

RESOURCES += \
    icon.qrc \
    src.qrc
