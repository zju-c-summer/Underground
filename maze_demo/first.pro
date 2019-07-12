#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T15:33:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = first
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Carousellmagewindow.cpp \
        block.cpp \
        game_control.cpp \
        interface.cpp \
        main.cpp \
        mainwindow.cpp \
        maze_model.cpp \
        player.cpp \
        prim.cpp \
        smallMap.cpp \
        viewer.cpp

HEADERS += \
        Carousellmagewindow.h \
        block.h \
        common_value.h \
        game_control.h \
        interface.h \
        mainwindow.h \
        maze_model.h \
        player.h \
        prim.h \
        smallMap.h \
        viewer.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

RC_FILE += ICON.rc
