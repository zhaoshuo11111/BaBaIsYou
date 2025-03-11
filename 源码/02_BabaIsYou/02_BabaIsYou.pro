#-------------------------------------------------
#
# Project created by QtCreator 2023-08-03T19:51:30
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02_BabaIsYou
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


SOURCES += \
        main.cpp \
        guide_scene.cpp \
    setting_scene.cpp \
    choose_scene.cpp \
    game_scene.cpp \
    pause_scene.cpp \
    block.cpp \
    animation.cpp \
    change_scene.cpp \
    edit_level.cpp \
    set_level_name.cpp \
    editor.cpp \
    term_borad.cpp \
    lblock.cpp \
    search.cpp

HEADERS += \
        guide_scene.h \
    config.h \
    setting_scene.h \
    choose_scene.h \
    game_scene.h \
    pause_scene.h \
    block.h \
    animation.h \
    change_scene.h \
    edit_level.h \
    set_level_name.h \
    editor.h \
    term_borad.h \
    lblock.h \
    search.h

FORMS += \
        guide_scene.ui \
    setting_scene.ui \
    choose_scene.ui \
    game_scene.ui \
    pause_scene.ui \
    change_scene.ui \
    edit_level.ui \
    set_level_name.ui \
    editor.ui \
    term_borad.ui \
    search.ui \
    edit_level.ui

CONFIG += resources_big

RESOURCES += \
    res.qrc \
    level.qrc \
    qss.qrc \
    map.qrc \
    music.qrc
