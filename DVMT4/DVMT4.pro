QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    as.cpp \
    autowav.cpp \
    cbm.cpp \
    center.cpp \
    copthread.cpp \
    cpsdialog.cpp \
    cslget.cpp \
    ctool.cpp \
    cvvcsymbol.cpp \
    dow.cpp \
    dvsym.cpp \
    egg.cpp \
    filescaner.cpp \
    fm.cpp \
    gpl.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    mulcslget.cpp \
    openwav.cpp \
    plugins.cpp \
    project.cpp \
    prset.cpp \
    psm.cpp \
    rundialog.cpp \
    search.cpp \
    symbolcheck.cpp \
    title.cpp \
    vch.cpp

HEADERS += \
    Version.h \
    as.h \
    autowav.h \
    cbm.h \
    center.h \
    copthread.h \
    cpsdialog.h \
    cslget.h \
    ctool.h \
    cvvcsymbol.h \
    dow.h \
    dvsym.h \
    egg.h \
    filescaner.h \
    fm.h \
    gpl.h \
    mainwindow.h \
    menu.h \
    mulcslget.h \
    openwav.h \
    plugins.h \
    project.h \
    prset.h \
    psm.h \
    rundialog.h \
    search.h \
    symbolcheck.h \
    title.h \
    vch.h

FORMS += \
    as.ui \
    autowav.ui \
    cbm.ui \
    center.ui \
    cpsdialog.ui \
    ctool.ui \
    dow.ui \
    egg.ui \
    fm.ui \
    gpl.ui \
    mainwindow.ui \
    menu.ui \
    openwav.ui \
    plugins.ui \
    prset.ui \
    psm.ui \
    rundialog.ui \
    search.ui \
    title.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(AuPlot/auplot.pri)
include(Plugin/DVMT_plugin.pri)

RESOURCES += \
    icon.qrc \
    src.qrc

RC_FILE += icon.rc

