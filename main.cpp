#include "mainwindow.h"
#include "signuppage.h"
#include "mainpage.h"
#include "loginpage.h"
#include "agholpage.h"
#include "storepage.h"
#include "aviculturepage.h"
#include "livestockpage.h"
#include "menupage.h"
#include "silopage.h"
#include "alfalfa_landpage.h"
#include "wheat_landpage.h"
#include <QApplication>
#include <QFile>

#include "user.h"

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    StorePage w;
    QFile styleSheetFile("../farm-project/nice.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    w.show();
    return a.exec();
}
