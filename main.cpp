#include "mainwindow.h"
#include "signuppage.h"
#include "loginpage.h"
#include "livestockpage.h"
#include "mainpage.h"
#include <QApplication>
#include <QFile>

#include "user.h"

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    LivestockPage w;
    QFile styleSheetFile("../farm-project/nice.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    w.show();

<<<<<<< HEAD
    ///////////////////////////////
    //User user;

   // Wheat_landWindow ww(user.wheat_land);
    //ww.show();

    //StoreWindow s(user.store);
    //s.show();
    ///////////////////////////////

=======
>>>>>>> e8398d7db82411fb385f592bb28ff6b7cdd73f27
    return a.exec();
}
