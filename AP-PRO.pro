QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    StoreWindow.cpp \
    aghol.cpp \
    agholpage.cpp \
    alfalfa_land.cpp \
    aviculture.cpp \
    aviculturepage.cpp \
    building.cpp \
    farm.cpp \
    habitat.cpp \
    land.cpp \
    livestock.cpp \
    livestockpage.cpp \
    loginpage.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    signuppage.cpp \
    silo.cpp \
    silopage.cpp \
    store.cpp \
    user.cpp \
    wheat_land.cpp \
    wheat_landpage.cpp

HEADERS += \
    StoreWindow.h \
    aghol.h \
    agholpage.h \
    alfalfa_land.h \
    aviculture.h \
    aviculturepage.h \
    building.h \
    farm.h \
    habitat.h \
    land.h \
    livestock.h \
    livestockpage.h \
    loginpage.h \
    mainpage.h \
    mainwindow.h \
    signuppage.h \
    silo.h \
    silopage.h \
    store.h \
    user.h \
    wheat_land.h \
    wheat_landpage.h

FORMS += \
    agholpage.ui \
    aviculturepage.ui \
    livestockpage.ui \
    loginpage.ui \
    mainpage.ui \
    mainwindow.ui \
    signuppage.ui \
    StoreWindow.ui \
    mainwindow.ui \
    silopage.ui \
    wheat_landpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pics_resource.qrc
