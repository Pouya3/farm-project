QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aghol.cpp \
    alfalfa_land.cpp \
    aviculture.cpp \
    building.cpp \
    farm.cpp \
    habitat.cpp \
    land.cpp \
    livestock.cpp \
    loginpage.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    signuppage.cpp \
    silo.cpp \
    store.cpp \
    user.cpp \
    wheat_land.cpp

HEADERS += \
    aghol.h \
    alfalfa_land.h \
    aviculture.h \
    building.h \
    farm.h \
    habitat.h \
    land.h \
    livestock.h \
    loginpage.h \
    mainpage.h \
    mainwindow.h \
    signuppage.h \
    silo.h \
    store.h \
    user.h \
    wheat_land.h

FORMS += \
    loginpage.ui \
    mainpage.ui \
    mainwindow.ui \
    signuppage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
