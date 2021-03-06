#-------------------------------------------------
#
# Project created by QtCreator 2018-09-14T21:17:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EndlessTunnelPort
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

INCLUDEPATH += \
            "/Users/gunnarkarlsson/git/glm"

SOURCES += \
        main.cpp \
    vertexbuf.cpp \
    indexbuf.cpp \
    ascii_to_geom.cpp \
    scene.cpp \
    shaperenderer.cpp \
    util.cpp \
    shader.cpp \
    scenemanager.cpp \
    textrenderer.cpp \
    anim.cpp \
    uiscene.cpp \
    ourshader.cpp \
    texture.cpp \
    texquad.cpp \
    welcomescene.cpp \
    dialogscene.cpp \
    playscene.cpp \
    obstacle.cpp \
    obstaclegenerator.cpp \
    sfxman.cpp \
    gamewindow.cpp

HEADERS += \
    vertexbuf.h \
    common.h \
    indexbuf.h \
    ascii_to_geom.h \
    scene.h \
    engine.h \
    joystick-support.h \
    our_key_codes.h \
    simplegeom.h \
    data/alphabet.inl \
    data/ascii_art.inl \
    data/blurb.inl \
    data/cube_geom.inl \
    data/our_shader.inl \
    data/strings.inl \
    data/tunnel_geom.inl \
    shaperenderer.h \
    util.h \
    shader.h \
    scenemanager.h \
    textrenderer.h \
    anim.h \
    uiscene.h \
    ourshader.h \
    texture.h \
    texquad.h \
    welcomescene.h \
    dialogscene.h \
    playscene.h \
    obstacle.h \
    gameconsts.h \
    obstaclegenerator.h \
    sfxman.h \
    gamewindow.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    trivial.vert \
    trivial.frag
