QT += widgets

TEMPLATE = lib
DEFINES += DVMT_PLUGIN_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AuPlot/qwavehandle.cpp \
    AuPlot/qwaveinfo.cpp \
    cvvcsymbol.cpp \
    dvmt_plugin.cpp \
    dvsym.cpp \
    plugindialog.cpp \
    project.cpp \
    vch.cpp

HEADERS += \
    AuPlot/qwavehandle.h \
    AuPlot/qwaveinfo.h \
    DVMT_Plugin_global.h \
    cvvcsymbol.h \
    dvmt_plugin.h \
    dvsym.h \
    plugindialog.h \
    project.h \
    vch.h

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
