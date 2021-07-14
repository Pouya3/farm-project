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
    alfalfamarket.cpp \
    aviculture.cpp \
    aviculturepage.cpp \
    building.cpp \
    chickenmarket.cpp \
    cowmarket.cpp \
    eggmarket.cpp \
    farm.cpp \
    file_functions.cpp \
    habitat.cpp \
    land.cpp \
    levelup12.cpp \
    levelup23.cpp \
    levelup34.cpp \
    levelup45.cpp \
    levelup56.cpp \
    levelup67.cpp \
    levelupkoli.cpp \
    livestock.cpp \
    livestockpage.cpp \
    loadingpage.cpp \
    loginpage.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    marketpage.cpp \
    menupage.cpp \
    milkmarket.cpp \
    nailmarket.cpp \
    rankingpage.cpp \
    sheepmarket.cpp \
    shovel_market.cpp \
    signuppage.cpp \
    silo.cpp \
    silopage.cpp \
    spacepage.cpp \
    spacepage_2.cpp \
    store.cpp \
    storepage.cpp \
    user.cpp \
    wheat_land.cpp \
    wheat_landpage.cpp \
    wheatmarket.cpp \
    woolmarket.cpp

HEADERS += \
    aghol.h \
    agholpage.h \
    alfalfa_land.h \
    alfalfa_landpage.h \
    alfalfamarket.h \
    aviculture.h \
    aviculturepage.h \
    building.h \
    chickenmarket.h \
    cowmarket.h \
    eggmarket.h \
    farm.h \
    file_functions.h \
    habitat.h \
    land.h \
    levelup12.h \
    levelup23.h \
    levelup34.h \
    levelup45.h \
    levelup56.h \
    levelup67.h \
    levelupkoli.h \
    livestock.h \
    livestockpage.h \
    loadingpage.h \
    loginpage.h \
    mainpage.h \
    mainwindow.h \
    marketpage.h \
    menupage.h \
    milkmarket.h \
    nailmarket.h \
    rankingpage.h \
    sheepmarket.h \
    shovel_market.h \
    signuppage.h \
    silo.h \
    silopage.h \
    spacepage.h \
    spacepage_2.h \
    store.h \
    storepage.h \
    user.h \
    wheat_land.h \
    wheat_landpage.h \
    wheatmarket.h \
    woolmarket.h

FORMS += \
    agholpage.ui \
    alfalfa_landpage.ui \
    alfalfamarket.ui \
    aviculturepage.ui \
    chickenmarket.ui \
    cowmarket.ui \
    eggmarket.ui \
    levelup12.ui \
    levelup23.ui \
    levelup34.ui \
    levelup45.ui \
    levelup56.ui \
    levelup67.ui \
    levelupkoli.ui \
    livestockpage.ui \
    loadingpage.ui \
    loginpage.ui \
    mainpage.ui \
    mainwindow.ui \
    marketpage.ui \
    menupage.ui \
    milkmarket.ui \
    nailmarket.ui \
    rankingpage.ui \
    sheepmarket.ui \
    shovel_market.ui \
    signuppage.ui \
    mainwindow.ui \
    silopage.ui \
    spacepage.ui \
    spacepage_2.ui \
    storepage.ui \
    wheat_landpage.ui \
    wheatmarket.ui \
    woolmarket.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pics_resource.qrc
