#include "mainwindow.h"
#include "signuppage.h"
#include "loginpage.h"
#include "mainpage.h"
#include <QApplication>
#include <QFile>

////
#include "Wheat_landWindow.h"
#include "user.h"
#include "StoreWindow.h"
////

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainPage w;
    QFile styleSheetFile("../farm-project/nice.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    w.show();

    ///////////////////////////////
    User user;

    Wheat_landWindow ww(user.wheat_land);
    ww.show();

    StoreWindow s(user.store);
    s.show();
    ///////////////////////////////

    return a.exec();
}
