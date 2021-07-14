#include "mainwindow.h"
#include "signuppage.h"
#include "shovel_market.h"
#include "mainpage.h"
#include "loginpage.h"
#include "cowmarket.h"
#include "rankingpage.h"
#include "alfalfamarket.h"

#include "chickenmarket.h"
#include "agholpage.h"
#include "marketpage.h"
#include "sheepmarket.h"
#include "storepage.h"
#include "levelup12.h"
#include "levelupkoli.h"
#include "aviculturepage.h"
#include "livestockpage.h"
#include "menupage.h"
#include "spacepage.h"
#include "spacepage_2.h"

#include "nailmarket.h"
#include "silopage.h"
#include "alfalfa_landpage.h"
#include "wheat_landpage.h"
#include "loadingpage.h"
#include "wheatmarket.h"
#include "milkmarket.h"
#include "eggmarket.h"
#include "woolmarket.h"
#include <QApplication>
#include <QFile>

#include "user.h"

int main(int argc, char *argv[])

{
    if(fopen("all users.json", "r") == NULL){ // "all users.json does not exist  //
        QJsonObject all_user_obj;                                                //
        QJsonArray users_array;                                                  //
                                                                                 //
        all_user_obj["users"] = users_array;                                     //
                                                                                 // do not modify this part
        QFile all_users_file("all users.json");                                  //
        all_users_file.open(QIODevice::WriteOnly);                               //
                                                                                 //
        QJsonDocument all_users_doc(all_user_obj);                               //
        all_users_file.write(all_users_doc.toJson());                            //

        all_users_file.close();
    }


    QApplication a(argc, argv);
    RankingPage w;
    QFile styleSheetFile("../farm-project/nice.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    w.show();
    return a.exec();
}
