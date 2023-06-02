QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    main.cpp \
    main_character.cpp \
    mainwindow.cpp

HEADERS += \
    game.h \
    main_character.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    sprites/Lluvia.png \
    sprites/Save.png \
    sprites/background.png \
    sprites/craiyon_224215_Sheet_of_tree_sprites_to_videogame.png \
    sprites/desert.png \
    sprites/personaje.png \
    sprites/player.png \
    sprites/prueba.png

RESOURCES += \
    Sprites.qrc \
    Sprites.qrc
