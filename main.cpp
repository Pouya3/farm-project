#include "mainwindow.h"
#include "signuppage.h"
#include "loginpage.h"
#include "mainpage.h"
#include <QApplication>
#include <QFile>

#include "user.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainPage w;
    QFile styleSheetFile("../farm-project/nice.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    w.show();

    return a.exec();
}
