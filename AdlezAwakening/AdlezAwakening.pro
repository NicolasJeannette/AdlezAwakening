QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Room.cpp \
    Vector2.cpp \
    Vector3.cpp \
    donjon.cpp \
    gamemanager.cpp \
    glwidgetdisplay.cpp \
    input.cpp \
    main.cpp \
    fenetreprincipale.cpp \
    player.cpp

HEADERS += \
    Room.h \
    Vector2.h \
    Vector3.h \
    donjon.h \
    fenetreprincipale.h \
    gamemanager.h \
    glwidgetdisplay.h \
    input.h \
    player.h

FORMS += \
    fenetreprincipale.ui

TRANSLATIONS += \
    AdlezAwakening_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
win32:LIBS += -lOpengl32\
              -lglu32

unix:LIBS += -lglut -lGLU
