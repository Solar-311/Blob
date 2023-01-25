QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/Empty.cpp \
    Model/Arene/Arene.cpp \
    Model/Attaque/Normale.cpp \
    Model/Attaque/Soin.cpp \
    Model/Attaque/Speciale.cpp \
    Model/Blob.cpp \
    Model/Joueur/Joueur.cpp \
    Model/Menu/ListBlob.cpp \
    Model/Type/Eau.cpp \
    Model/Type/Feu.cpp \
    Model/Type/Plante.cpp \
    Model/Type/Type.cpp \
    Model/Utils/Utils.cpp \
    View/Empty.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Controller/Empty.h \
    Model/Arene/Arene.h \
    Model/Attaque/Normale.h \
    Model/Attaque/Soin.h \
    Model/Attaque/Speciale.h \
    Model/Blob.h \
    Model/Joueur/Joueur.h \
    Model/Menu/ListBlob.h \
    Model/Type/Eau.h \
    Model/Type/Feu.h \
    Model/Type/Plante.h \
    Model/Type/Type.h \
    Model/Utils/Utils.h \
    View/Empty.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Others/Images/Background.png \
    Others/Images/BlobFabio.gif \
    Others/Images/GreenBlob.gif \
    Others/Images/Maskass.png
