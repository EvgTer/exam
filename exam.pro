QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    admin.cpp \
    adventure.cpp \
    dialog_addadv.cpp \
    dialog_balance.cpp \
    dialog_delete.cpp \
    game.cpp \
    horror.cpp \
    main.cpp \
    mainwindow.cpp \
    mmorpg.cpp \
    sandbox.cpp \
    shooter.cpp \
    user.cpp

HEADERS += \
    account.h \
    admin.h \
    adventure.h \
    dialog_addadv.h \
    dialog_balance.h \
    dialog_delete.h \
    game.h \
    horror.h \
    mainwindow.h \
    mmorpg.h \
    sandbox.h \
    shooter.h \
    user.h

FORMS += \
    dialog_addadv.ui \
    dialog_balance.ui \
    dialog_delete.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    logo/GGStore_LOGO.jpg

RESOURCES += \
    logo.qrc
