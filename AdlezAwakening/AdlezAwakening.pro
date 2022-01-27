QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Asset.cpp \
    GameManager.cpp \
    Stat.cpp \
    Vector2.cpp \
    Vector3.cpp \
    glwidgetdisplay.cpp \
    main.cpp \
    fenetreprincipale.cpp

HEADERS += \
    Asset.h \
    GameManager.h \
    Stat.h \
    Vector2.h \
    Vector3.h \
    fenetreprincipale.h \
    glwidgetdisplay.h

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
