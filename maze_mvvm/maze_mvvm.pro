QT += gui core widgets

CONFIG += c++17 console
CONFIG -= app_bundle

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
        app/mazeapp.cpp \
        app/view/game_control.cpp \
        app/view/smallMap.cpp \
        app/view/smallmap_notification.cpp \
        app/view/viewer.cpp \
        app/window/Carousellmagewindow.cpp \
        app/window/interface.cpp \
        app/window/mainwindow.cpp \
        app/window/mainwindow_notification.cpp \
        main.cpp \
        utility/common/block.cpp \
        utility/common/player.cpp \
        utility/model/maze_model.cpp \
        utility/model/prim.cpp \
        utility/viewmodel/enemyflushcommand.cpp \
        utility/viewmodel/generatecommand.cpp \
        utility/viewmodel/mazeViewModel.cpp \
        utility/viewmodel/mazeviewmodel_notification.cpp \
        utility/viewmodel/movecommand.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    app/mazeapp.h \
    app/view/game_control.h \
    app/view/smallMap.h \
    app/view/smallmap_notification.h \
    app/view/ui_widget.h \
    app/view/viewer.h \
    app/window/Carousellmagewindow.h \
    app/window/interface.h \
    app/window/mainwindow.h \
    app/window/mainwindow_notification.h \
    app/window/ui_widget.h \
    utility/common/base.h \
    utility/common/block.h \
    utility/common/common_value.h \
    utility/common/player.h \
    utility/model/maze_model.h \
    utility/model/prim.h \
    utility/viewmodel/enemyflushcommand.h \
    utility/viewmodel/generatecommand.h \
    utility/viewmodel/mazeViewModel.h \
    utility/viewmodel/mazeviewmodel_notification.h \
    utility/viewmodel/movecommand.h

FORMS += \
    app/window/mainwindow.ui

DISTFILES += \
    image/background.png \
    image/enter.png \
    image/enter_2.png \
    image/exit.png \
    image/exit_2.png \
    image/exitbutton.png \
    image/exitbutton_hover.png \
    image/exitbutton_pressed.png \
    image/icon.png \
    image/image1.jpg \
    image/image2.jpg \
    image/image3.jpg \
    image/loading.gif \
    image/man_down.jpg \
    image/man_down_1.png \
    image/man_left.jpg \
    image/man_left_1.png \
    image/man_right.jpg \
    image/man_right_1.png \
    image/man_up.jpg \
    image/man_up_1.png \
    image/monster_l.png \
    image/monster_r.png \
    image/playbutton.png \
    image/playbutton_hover.png \
    image/playbutton_pressed.png \
    image/title.png \
    image/wall.png \
    image/wall_1.png \
    image/wall_dark.png

RESOURCES += \
    res.qrc

RC_FILE += ICON.rc
