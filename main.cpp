#include "mainwindow.h"
#include "signuppage.h"
#include "loginpage.h"
#include "agholpage.h"
#include "aviculturepage.h"
#include "livestockpage.h"
#include "mainpage.h"
#include "silopage.h"
#include "wheat_landpage.h"
#include <QApplication>
#include <QFile>

#include "user.h"

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    Wheat_landPage w;
    QFile styleSheetFile("../farm-project/nice.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    w.show();
    return a.exec();
}
