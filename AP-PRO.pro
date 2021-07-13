QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aghol.cpp \
    agholpage.cpp \
    alfalfa_land.cpp \
    alfalfa_landpage.cpp \
    aviculture.cpp \
    aviculturepage.cpp \
    building.cpp \
    farm.cpp \
    file_functions.cpp \
    habitat.cpp \
    land.cpp \
    livestock.cpp \
    livestockpage.cpp \
    loadingpage.cpp \
    loginpage.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    marketpage.cpp \
    menupage.cpp \
    nailmarket.cpp \
    sheepmarket.cpp \
    shovel_market.cpp \
    signuppage.cpp \
    silo.cpp \
    silopage.cpp \
    store.cpp \
    storepage.cpp \
    user.cpp \
    wheat_land.cpp \
    wheat_landpage.cpp

HEADERS += \
    aghol.h \
    agholpage.h \
    alfalfa_land.h \
    alfalfa_landpage.h \
    aviculture.h \
    aviculturepage.h \
    building.h \
    farm.h \
    file_functions.h \
    habitat.h \
    land.h \
    livestock.h \
    livestockpage.h \
    loadingpage.h \
    loginpage.h \
    mainpage.h \
    mainwindow.h \
    marketpage.h \
    menupage.h \
    nailmarket.h \
    sheepmarket.h \
    shovel_market.h \
    signuppage.h \
    silo.h \
    silopage.h \
    store.h \
    storepage.h \
    user.h \
    wheat_land.h \
    wheat_landpage.h

FORMS += \
    agholpage.ui \
    alfalfa_landpage.ui \
    aviculturepage.ui \
    livestockpage.ui \
    loadingpage.ui \
    loginpage.ui \
    mainpage.ui \
    mainwindow.ui \
    marketpage.ui \
    menupage.ui \
    nailmarket.ui \
    sheepmarket.ui \
    shovel_market.ui \
    signuppage.ui \
    mainwindow.ui \
    silopage.ui \
    storepage.ui \
    wheat_landpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pics_resource.qrc
