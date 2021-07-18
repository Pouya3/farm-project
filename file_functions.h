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
#include <QMultiMap>

#include "aghol.h"
#include "alfalfa_land.h"
#include "aviculture.h"
#include "building.h"
#include "habitat.h"
#include "land.h"
#include "livestock.h"
#include "silo.h"
#include "store.h"
#include "user.h"
#include "wheat_land.h"




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


std::vector<std::pair<int, QString>> Get_users_for_ranking();
void Save_user(User* user);

#endif // FILE_FUNCTIONS_H
