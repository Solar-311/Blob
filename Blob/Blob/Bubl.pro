QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/Game/Blob/Blob.cpp \
    src/Game/Blob/Type/Eau.cpp \
    src/Game/Blob/Type/Feu.cpp \
    src/Game/Blob/Type/Plante.cpp \
    src/Game/Blob/Type/Type.cpp

HEADERS += \
    ../../../../../../src/Game/Blob/Blob.h \
    mainwindow.h \
    src/Game/Blob/Blob.h \
    src/Game/Blob/Type/Eau.h \
    src/Game/Blob/Type/Feu.h \
    src/Game/Blob/Type/Plante.h \
    src/Game/Blob/Type/Type.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
