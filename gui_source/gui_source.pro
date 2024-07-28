QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nfd
TEMPLATE = app

macx {
    TARGET = NFD
}

CONFIG += c++11

include(../build.pri)

XCONFIG += use_capstone_x86

SOURCES += \
    guimainwindow.cpp \
    dialogabout.cpp \
    main_gui.cpp \
    dialogoptions.cpp

HEADERS  += \
    guimainwindow.h \
    ../global.h \
    dialogabout.h \
    dialogoptions.h

FORMS    += \
    guimainwindow.ui \
    dialogabout.ui \
    dialogoptions.ui

!contains(XCONFIG, nfd_widget) {
    XCONFIG += nfd_widget
    include(../nfd_widget/nfd_widget.pri)
}

!contains(XCONFIG, xoptionswidget) {
    XCONFIG += xoptionswidget
    include(../XOptions/xoptionswidget.pri)
}

!contains(XCONFIG, xaboutwidget) {
    XCONFIG += xaboutwidget
    include(../XAboutWidget/xaboutwidget.pri)
}

win32 {
    RC_ICONS = ../icons/main.ico
    CONFIG -= embed_manifest_exe
    QMAKE_MANIFEST = windows.manifest.xml
    VERSION = 0.010.0.0
    QMAKE_TARGET_COMPANY = NTInfo
    QMAKE_TARGET_PRODUCT = Nauz File Detector
    QMAKE_TARGET_DESCRIPTION = Nauz File Detector(NFD) is a linker/compiler/packer identifier utility.
    QMAKE_TARGET_COPYRIGHT = horsicq@gmail.com
}

macx {
    ICON = ../icons/main.icns
}

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../LICENSE \
    ../README.md \
    ../changelog.txt \
    ../release_version.txt \
    CMakeLists.txt
