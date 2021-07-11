#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QByteArray>
#include <iostream>
#include <direct.h>
#include <QDir>
#include <vector>
#include <map>

#include "E:/visual studio projects/farm-project/aghol.h"
#include "E:/visual studio projects/farm-project/alfalfa_land.h"
#include "E:/visual studio projects/farm-project/aviculture.h"
#include "E:/visual studio projects/farm-project/building.h"
#include "E:/visual studio projects/farm-project/habitat.h"
#include "E:/visual studio projects/farm-project/land.h"
#include "E:/visual studio projects/farm-project/livestock.h"
#include "E:/visual studio projects/farm-project/silo.h"
#include "E:/visual studio projects/farm-project/store.h"
#include "E:/visual studio projects/farm-project/user.h"
#include "E:/visual studio projects/farm-project/Wheat_land.h"


bool Create_new_user_files(QString username, QString name, QString password, QString email);
//      | | | | |
//      V V V V V
// return values :
// false == username exists | true == username does not exist (account created successfully)

int Login_user(QString username, QString password, User* user);
//      | | | | |
//      V V V V V
// return values :
// 0 == user does not exist
// 1 == user exists but wrong password
// 2 == user exists and correct password (succesfull login)


map<QString, int> Get_users_for_ranking();
void Save_user(User* user);

#endif // FILE_FUNCTIONS_H
