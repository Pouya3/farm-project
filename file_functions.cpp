#include "file_functions.h"


bool Create_new_user_files(QString username, QString name, QString password, QString email){ // return false for "user exists | return true for "user does not exist //

    if(QDir(username).exists() == 0){ // directory(user) doesnt exist

        QFile all_users_file("all users.json");                                           //                  //
        all_users_file.open(QIODevice::ReadOnly);                                         //                  //
        QByteArray all_users_byte_array = all_users_file.readAll();                       // read             //
        QJsonDocument all_users_doc = QJsonDocument::fromJson(all_users_byte_array);      //                  //
        QJsonObject all_users_obj = all_users_doc.object();                               //                  //
        all_users_file.close();                                                                               //
                                                                                          //                  //
        QJsonArray users_array;                                                           //                  //
        users_array = all_users_obj.value("users").toArray();                             // add new username // add new username to "all users.json"
        users_array.append(username);                                                     //                  //
        all_users_obj["users"] = users_array;                                                                 //
                                                                                          //                  //
        all_users_file.open(QIODevice::WriteOnly);                                        //                  //
        QJsonDocument all_users_doc_write(all_users_obj);                                 // write            //
        all_users_file.write(all_users_doc_write.toJson());                               //                  //
        all_users_file.close();


        QJsonObject user_obj;
        QJsonObject wheat_land_obj;
        QJsonObject alfalfa_land_obj;
        QJsonObject aviculture_obj;
        QJsonObject livestock_obj;
        QJsonObject aghol_obj;
        QJsonObject store_obj;
        QJsonObject silo_obj;

        QJsonArray milk_info_number_array;
        QJsonArray milk_info_timer_array;

        aghol_obj["level"] = 0;
        aghol_obj["total_storage"] = 0;
        aghol_obj["used_storage"] = 0;
        aghol_obj["upgrade_timer"] = 0;
        aghol_obj["building_status"] = 0;
        aghol_obj["feeding_status"] = 0;
        aghol_obj["feeding_timer"] = 0;
        aghol_obj["building_timer"] = 0;

        alfalfa_land_obj["level"] = 0;
        alfalfa_land_obj["total_area"] = 0;
        alfalfa_land_obj["cultivated_area"] = 0;
        alfalfa_land_obj["cultivation_status"] = 0;
        alfalfa_land_obj["ripening_timer"] = 0;
        alfalfa_land_obj["upgrade_timer"] = 0;
        alfalfa_land_obj["plowed_area"] = 0;
        alfalfa_land_obj["building_status"] = 0;
        alfalfa_land_obj["building_timer"] = 0;
        alfalfa_land_obj["plowing_timer"] = 0;

        aviculture_obj["level"] = 0;
        aviculture_obj["total_storage"] = 0;
        aviculture_obj["used_storage"] = 0;
        aviculture_obj["upgrade_timer"] = 0;
        aviculture_obj["building_status"] = 0;
        aviculture_obj["feeding_status"] = 0;
        aviculture_obj["feeding_timer"] = 0;
        aviculture_obj["building_timer"] = 0;

        livestock_obj["level"] = 0;
        livestock_obj["total_storage"] = 0;
        livestock_obj["used_storage"] = 0;
        livestock_obj["upgrade_timer"] = 0;
        livestock_obj["building_status"] = 0;
        livestock_obj["feeding_status"] = 0;
        livestock_obj["feeding_timer"] = 0;
        livestock_obj["building_timer"] = 0;

        silo_obj["level"] = 1;
        silo_obj["total_storage"] = 10;
        silo_obj["used_storage"] = 1;
        silo_obj["upgrade_timer"] = 0;

        store_obj["level"] = 1;
        store_obj["total_storage"] = 5;
        store_obj["used_storage"] = 2;
        store_obj["upgrade_timer"] = 0;
        store_obj["shovel"] = 0;
        store_obj["nail"] = 1;
        store_obj["alfalfa"] = 1;
        store_obj["egg"] = 0;
        store_obj["milk"] = 0;
        store_obj["wool"] = 0;
        store_obj["milk_info_number_array"] = milk_info_number_array;
        store_obj["milk_info_timer_array"] = milk_info_timer_array;

        user_obj["name"] = name;
        user_obj["username"] = username;
        user_obj["password"] = password;
        user_obj["email"] = email;
        user_obj["level"] = 1;
        user_obj["experience"] = 0;
        user_obj["max_experience"] = 10;
        user_obj["time"] = 0;
        user_obj["coin"] = 20;

        wheat_land_obj["level"] = 1;
        wheat_land_obj["total_area"] = 5;
        wheat_land_obj["cultivated_area"] = 0;
        wheat_land_obj["cultivation_status"] = 0;
        wheat_land_obj["ripening_timer"] = 0;
        wheat_land_obj["upgrade_timer"] = 0;


        QDir().mkdir(username);

        QFile user_file(username + "//user.json");
        QFile wheat_land_file(username + "//wheat_land.json");
        QFile alfalfa_land_file(username + "//alfalfa_land.json");
        QFile aviculture_file(username + "//aviculture.json");
        QFile livestock_file(username + "//livestock.json");
        QFile aghol_file(username + "//aghol.json");
        QFile store_file(username + "//store.json");
        QFile silo_file(username + "//silo.json");

        user_file.open(QIODevice::WriteOnly);
        wheat_land_file.open(QIODevice::WriteOnly);
        alfalfa_land_file.open(QIODevice::WriteOnly);
        aviculture_file.open(QIODevice::WriteOnly);
        livestock_file.open(QIODevice::WriteOnly);
        aghol_file.open(QIODevice::WriteOnly);
        store_file.open(QIODevice::WriteOnly);
        silo_file.open(QIODevice::WriteOnly);

        QJsonDocument user_doc(user_obj);
        QJsonDocument wheat_land_doc(wheat_land_obj);
        QJsonDocument alfalfa_land_doc(alfalfa_land_obj);
        QJsonDocument aviculture_doc(aviculture_obj);
        QJsonDocument livestock_doc(livestock_obj);
        QJsonDocument aghol_doc(aghol_obj);
        QJsonDocument store_doc(store_obj);
        QJsonDocument silo_doc(silo_obj);

        user_file.write(user_doc.toJson());
        wheat_land_file.write(wheat_land_doc.toJson());
        alfalfa_land_file.write(alfalfa_land_doc.toJson());
        aviculture_file.write(aviculture_doc.toJson());
        livestock_file.write(livestock_doc.toJson());
        aghol_file.write(aghol_doc.toJson());
        store_file.write(store_doc.toJson());
        silo_file.write(silo_doc.toJson());

        user_file.flush();
        wheat_land_file.flush();
        alfalfa_land_file.flush();
        aviculture_file.flush();
        livestock_file.flush();
        aghol_file.flush();
        store_file.flush();
        silo_file.flush();

        user_file.close();
        wheat_land_file.close();
        alfalfa_land_file.close();
        aviculture_file.close();
        livestock_file.close();
        aghol_file.close();
        store_file.close();
        silo_file.close();

        return true;
    }
    else{ // directory(user) exists
        return false;
    }
}

int Login_user(QString username, QString password, User* user){
    // return values :
    // 0 == user does not exist
    // 1 == user exists but wrong password
    // 2 == user exists and correct password (succesfull login)

    if(QDir(username).exists() == 0){ // user does not exist
        return 0;
    }
    else{
        QFile user_file(username + "//user.json");
        user_file.open(QIODevice::ReadOnly);

        QByteArray user_byte_array;
        user_byte_array = user_file.readAll();

        QJsonDocument user_doc;
        user_doc = QJsonDocument::fromJson(user_byte_array);

        QJsonObject user_obj;
        user_obj = user_doc.object();

        if(user_obj.value("password").toString() == password){ // correct password
            user->Set_name(user_obj.value("name").toString());
            user->set_username(user_obj.value("username").toString());
            user->Set_password(user_obj.value("password").toString());
            user->Set_email(user_obj.value("email").toString());
            user->Set_level(user_obj.value("level").toInt());
            user->Set_max_experience(user_obj.value("max_experience").toInt());
            user->Set_experience(user_obj.value("experience").toInt());
            user->Set_time(user_obj.value("time").toInt());
            user->Set_coin(user_obj.value("coin").toInt());
            user_file.close();

            QFile wheat_land_file(username + "//wheat_land.json");
            QFile alfalfa_land_file(username + "//alfalfa_land.json");
            QFile aviculture_file(username + "//aviculture.json");
            QFile livestock_file(username + "//livestock.json");
            QFile aghol_file(username + "//aghol.json");
            QFile store_file(username + "//store.json");
            QFile silo_file(username + "//silo.json");

            wheat_land_file.open(QIODevice::ReadOnly);
            alfalfa_land_file.open(QIODevice::ReadOnly);
            aviculture_file.open(QIODevice::ReadOnly);
            livestock_file.open(QIODevice::ReadOnly);
            aghol_file.open(QIODevice::ReadOnly);
            store_file.open(QIODevice::ReadOnly);
            silo_file.open(QIODevice::ReadOnly);

            QByteArray wheat_land_byte_array;
            QByteArray alfalfa_land_byte_array;
            QByteArray aviculture_byte_array;
            QByteArray livesctock_byte_array;
            QByteArray aghol_byte_array;
            QByteArray store_byte_array;
            QByteArray silo_byte_array;

            wheat_land_byte_array = wheat_land_file.readAll();
            alfalfa_land_byte_array = alfalfa_land_file.readAll();
            aviculture_byte_array = aviculture_file.readAll();
            livesctock_byte_array = livestock_file.readAll();
            aghol_byte_array = aghol_file.readAll();
            store_byte_array = store_file.readAll();
            silo_byte_array = silo_file.readAll();

            QJsonDocument wheat_land_doc;
            QJsonDocument alfalfa_land_doc;
            QJsonDocument aviculture_doc;
            QJsonDocument livestock_doc;
            QJsonDocument aghol_doc;
            QJsonDocument store_doc;
            QJsonDocument silo_doc;

            wheat_land_doc = QJsonDocument::fromJson(wheat_land_byte_array);
            alfalfa_land_doc = QJsonDocument::fromJson(alfalfa_land_byte_array);
            aviculture_doc = QJsonDocument::fromJson(aviculture_byte_array);
            livestock_doc = QJsonDocument::fromJson(livesctock_byte_array);
            aghol_doc = QJsonDocument::fromJson(aghol_byte_array);
            store_doc = QJsonDocument::fromJson(store_byte_array);
            silo_doc = QJsonDocument::fromJson(silo_byte_array);

            QJsonObject wheat_land_obj;
            QJsonObject alfalfa_land_obj;
            QJsonObject aviculture_obj;
            QJsonObject livestock_obj;
            QJsonObject aghol_obj;
            QJsonObject store_obj;
            QJsonObject silo_obj;

            wheat_land_obj = wheat_land_doc.object();
            alfalfa_land_obj = alfalfa_land_doc.object();
            aviculture_obj = aviculture_doc.object();
            livestock_obj = livestock_doc.object();
            aghol_obj=aghol_doc.object();
            store_obj = store_doc.object();
            silo_obj = silo_doc.object();

            user->wheat_land->Set_level(wheat_land_obj.value("level").toInt());
            user->wheat_land->Set_total_area(wheat_land_obj.value("total_area").toInt());
            user->wheat_land->Set_cultivated_area(wheat_land_obj.value("cultivated_area").toInt());
            user->wheat_land->Set_cultivation_status(wheat_land_obj.value("cultivation_status").toInt());
            user->wheat_land->Set_ripening_timer(wheat_land_obj.value("ripening_timer").toInt());
            user->wheat_land->Set_upgrade_timer(wheat_land_obj.value("upgrade_timer").toInt());
            wheat_land_file.close();

            user->alfalfa_land->Set_level(alfalfa_land_obj.value("level").toInt());
            user->alfalfa_land->Set_total_area(alfalfa_land_obj.value("total_area").toInt());
            user->alfalfa_land->Set_cultivated_area(alfalfa_land_obj.value("cultivated_area").toInt());
            user->alfalfa_land->Set_cultivation_status(alfalfa_land_obj.value("cultivation_status").toInt());
            user->alfalfa_land->Set_ripening_timer(alfalfa_land_obj.value("ripening_timer").toInt());
            user->alfalfa_land->Set_upgrade_timer(alfalfa_land_obj.value("upgrade_timer").toInt());
            user->alfalfa_land->Set_plowed_area(alfalfa_land_obj.value("plowed_area").toInt());
            user->alfalfa_land->Set_building_status(alfalfa_land_obj.value("building_status").toInt());
            user->alfalfa_land->Set_building_timer(alfalfa_land_obj.value("building_timer").toInt());
            user->alfalfa_land->Set_plowing_timer(alfalfa_land_obj.value("plowing_timer").toInt());
            alfalfa_land_file.close();

            user->aviculture->Set_level(aviculture_obj.value("level").toInt());
            user->aviculture->Set_total_storage(aviculture_obj.value("total_storage").toInt());
            user->aviculture->Set_used_storage(aviculture_obj.value("used_storage").toInt());
            user->aviculture->Set_upgrade_timer(aviculture_obj.value("upgrade_timer").toInt());
            user->aviculture->Set_building_status(aviculture_obj.value("building_status").toInt());
            user->aviculture->Set_feeding_status(aviculture_obj.value("feeding_status").toInt());
            user->aviculture->Set_feeding_timer(aviculture_obj.value("feeding_timer").toInt());
            user->aviculture->Set_building_timer(aviculture_obj.value("building_timer").toInt());
            aviculture_file.close();

            user->livestock->Set_level(livestock_obj.value("level").toInt());
            user->livestock->Set_total_storage(livestock_obj.value("total_storage").toInt());
            user->livestock->Set_used_storage(livestock_obj.value("used_storage").toInt());
            user->livestock->Set_upgrade_timer(livestock_obj.value("upgrade_timer").toInt());
            user->livestock->Set_building_status(livestock_obj.value("building_status").toInt());
            user->livestock->Set_feeding_status(livestock_obj.value("feeding_status").toInt());
            user->livestock->Set_feeding_timer(livestock_obj.value("feeding_timer").toInt());
            user->livestock->Set_building_timer(livestock_obj.value("building_timer").toInt());
            livestock_file.close();

            user->aghol->Set_level(aghol_obj.value("level").toInt());
            user->aghol->Set_total_storage(aghol_obj.value("total_storage").toInt());
            user->aghol->Set_used_storage(aghol_obj.value("used_storage").toInt());
            user->aghol->Set_upgrade_timer(aghol_obj.value("upgrade_timer").toInt());
            user->aghol->Set_building_status(aghol_obj.value("building_status").toInt());
            user->aghol->Set_feeding_status(aghol_obj.value("feeding_status").toInt());
            user->aghol->Set_feeding_timer(aghol_obj.value("feeding_timer").toInt());
            user->aghol->Set_building_timer(aghol_obj.value("building_timer").toInt());
            aghol_file.close();

            user->store->Set_level(store_obj.value("level").toInt());
            user->store->Set_total_storage(store_obj.value("total_storage").toInt());
            user->store->Set_used_storage(store_obj.value("used_storage").toInt());
            user->store->Set_upgrade_timer(store_obj.value("upgrade_timer").toInt());
            user->store->Set_object(1, store_obj.value("shovel").toInt());
            user->store->Set_object(2, store_obj.value("nail").toInt());
            user->store->Set_object(3, store_obj.value("alfalfa").toInt());
            user->store->Set_object(4, store_obj.value("egg").toInt());
            user->store->Set_object(5, store_obj.value("milk").toInt());
            user->store->Set_object(6, store_obj.value("wool").toInt());
            std::vector<std::pair<int, int>> milk_info_vector;
            for(int i = 0; i < store_obj.value("milk_info_number_array").toArray().size(); i++){
                milk_info_vector.push_back(std::pair<int, int>(store_obj.value("milk_info_number_array")[i].toInt(),store_obj.value("milk_info_timer_array")[i].toInt()));
            }
            user->store->Set_milk_info(milk_info_vector);
            store_file.close();

            user->silo->Set_level(silo_obj.value("level").toInt());
            user->silo->Set_total_storage(silo_obj.value("total_storage").toInt());
            user->silo->Set_used_storage(silo_obj.value("used_storage").toInt());
            user->silo->Set_upgrade_timer(silo_obj.value("upgrade_timer").toInt());
            silo_file.close();

            return 2;
        }
        user_file.close();
        return 1;
    }
}

std::vector<std::pair<int, QString>> Get_users_for_ranking(){
    QFile all_users_file("all users.json");                                       //
    all_users_file.open(QIODevice::ReadOnly);                                     //
                                                                                  //
    QByteArray all_users_byte_array = all_users_file.readAll();                   //
                                                                                  //
    QJsonDocument all_users_doc = QJsonDocument::fromJson(all_users_byte_array);  // get array of usernames
                                                                                  //
    QJsonObject all_users_obj = all_users_doc.object();                           //
                                                                                  //
    QJsonArray users_array = all_users_obj["users"].toArray();                    //
                                                                                  //
    all_users_file.close();                                                       //

/////////////////////////////////////////////////////////

    std::vector<std::pair<int, QString>> users_vector;
    int i;
    for(i=0; i<users_array.size(); i++){
        QFile user_file(users_array[i].toString() + "//user.json");
        user_file.open(QIODevice::ReadOnly);

        QByteArray user_byte_array = user_file.readAll();

        QJsonDocument user_doc = QJsonDocument::fromJson(user_byte_array);

        QJsonObject user_obj = user_doc.object();

        users_vector.push_back(std::pair<int, QString>(user_obj["experience"].toInt(), user_obj["username"].toString()));

        user_file.close();
    }

    std::sort(users_vector.begin(), users_vector.end(), [](auto &left, auto &right) {     //
        return left.first < right.first;                                                  // sorting
    });                                                                                   //

    return users_vector;
}

void Save_user(User* user){
    QJsonObject user_obj;
    QJsonObject wheat_land_obj;
    QJsonObject alfalfa_land_obj;
    QJsonObject aviculture_obj;
    QJsonObject livestock_obj;
    QJsonObject aghol_obj;
    QJsonObject store_obj;
    QJsonObject silo_obj;

    QJsonArray milk_info_number_array;
    QJsonArray milk_info_timer_array;

    aghol_obj["level"] = user->aghol->Get_level();
    aghol_obj["total_storage"] = user->aghol->Get_total_storage();
    aghol_obj["used_storage"] = user->aghol->Get_used_storage();
    aghol_obj["upgrade_timer"] = user->aghol->Get_upgrade_timer();
    aghol_obj["building_status"] = user->aghol->Get_building_status();
    aghol_obj["feeding_status"] = user->aghol->Get_feeding_status();
    aghol_obj["feeding_timer"] = user->aghol->Get_feeding_timer();
    aghol_obj["building_timer"] = user->aghol->Get_building_timer();

    alfalfa_land_obj["level"] = user->alfalfa_land->Get_level();
    alfalfa_land_obj["total_area"] = user->alfalfa_land->Get_total_area();
    alfalfa_land_obj["cultivated_area"] = user->alfalfa_land->Get_cultivated_area();
    alfalfa_land_obj["cultivation_status"] = user->alfalfa_land->Get_cultivation_status();
    alfalfa_land_obj["ripening_timer"] = user->alfalfa_land->Get_ripening_timer();
    alfalfa_land_obj["plowed_area"] = user->alfalfa_land->Get_plowed_area();
    alfalfa_land_obj["building_status"] = user->alfalfa_land->Get_building_status();
    alfalfa_land_obj["building_timer"] = user->alfalfa_land->Get_building_timer();
    alfalfa_land_obj["plowing_timer"] = user->alfalfa_land->Get_plowing_timer();

    aviculture_obj["level"] = user->aviculture->Get_level();
    aviculture_obj["total_storage"] = user->aviculture->Get_total_storage();
    aviculture_obj["used_storage"] = user->aviculture->Get_used_storage();
    aviculture_obj["upgrade_timer"] = user->aviculture->Get_upgrade_timer();
    aviculture_obj["building_status"] = user->aviculture->Get_building_status();
    aviculture_obj["feeding_status"] = user->aviculture->Get_feeding_status();
    aviculture_obj["feeding_timer"] = user->aviculture->Get_feeding_timer();
    aviculture_obj["building_timer"] = user->aviculture->Get_building_timer();

    livestock_obj["level"] = user->livestock->Get_level();
    livestock_obj["total_storage"] = user->livestock->Get_total_storage();
    livestock_obj["used_storage"] = user->livestock->Get_used_storage();
    livestock_obj["upgrade_timer"] = user->livestock->Get_upgrade_timer();
    livestock_obj["building_status"] = user->livestock->Get_building_status();
    livestock_obj["feeding_status"] = user->livestock->Get_feeding_status();
    livestock_obj["feeding_timer"] = user->livestock->Get_feeding_timer();
    livestock_obj["building_timer"] = user->livestock->Get_building_timer();

    silo_obj["level"] = user->silo->Get_level();
    silo_obj["total_storage"] = user->silo->Get_total_storage();
    silo_obj["used_storage"] = user->silo->Get_used_storage();
    silo_obj["upgrade_timer"] = user->silo->Get_upgrade_timer();

    store_obj["level"] = user->store->Get_level();
    store_obj["total_storage"] = user->store->Get_total_storage();
    store_obj["used_storage"] = user->store->Get_used_storage();
    store_obj["upgrade_timer"] = user->store->Get_upgrade_timer();
    store_obj["shovel"] = user->store->Get_object(1);
    store_obj["nail"] = user->store->Get_object(2);
    store_obj["alfalfa"] = user->store->Get_object(3);
    store_obj["egg"] = user->store->Get_object(4);
    store_obj["milk"] = user->store->Get_object(5);
    store_obj["wool"] = user->store->Get_object(6);
    if(user->store->Get_milk_info().size() != 0){
        std::vector<std::pair<int, int>>::iterator vector_iter;
        std::vector<std::pair<int, int>> milk_vect;
        milk_vect = user->store->Get_milk_info();
        vector_iter = milk_vect.begin();
        do{
            milk_info_number_array.push_back(vector_iter->first);
            milk_info_timer_array.push_back(vector_iter->second);

            vector_iter++;
        }while(vector_iter != milk_vect.end());
    }
    store_obj["milk_info_number_array"] = milk_info_number_array;
    store_obj["milk_info_timer_array"] = milk_info_timer_array;

    user_obj["name"] = user->Get_name();
    user_obj["username"] = user->Get_username();
    user_obj["password"] = user->Get_password();
    user_obj["email"] = user->Get_email();
    user_obj["level"] = user->Get_level();
    user_obj["experience"] = user->Get_experience();
    user_obj["max_experience"] = user->Get_max_experience();
    user_obj["time"] = user->Get_time();
    user_obj["coin"] = user->Get_coin();

    wheat_land_obj["level"] = user->wheat_land->Get_level();
    wheat_land_obj["total_area"] = user->wheat_land->Get_total_area();
    wheat_land_obj["cultivated_area"] = user->wheat_land->Get_cultivated_area();
    wheat_land_obj["cultivation_status"] = user->wheat_land->Get_cultivation_status();
    wheat_land_obj["ripening_timer"] = user->wheat_land->Get_ripening_timer();

    QFile user_file(user->Get_username() + "//user.json");
    QFile wheat_land_file(user->Get_username() + "//wheat_land.json");
    QFile alfalfa_land_file(user->Get_username() + "//alfalfa_land.json");
    QFile aviculture_file(user->Get_username() + "//aviculture.json");
    QFile livestock_file(user->Get_username() + "//livestock.json");
    QFile aghol_file(user->Get_username() + "//aghol.json");
    QFile store_file(user->Get_username() + "//store.json");
    QFile silo_file(user->Get_username() + "//silo.json");

    user_file.open(QIODevice::WriteOnly);
    wheat_land_file.open(QIODevice::WriteOnly);
    alfalfa_land_file.open(QIODevice::WriteOnly);
    aviculture_file.open(QIODevice::WriteOnly);
    livestock_file.open(QIODevice::WriteOnly);
    aghol_file.open(QIODevice::WriteOnly);
    store_file.open(QIODevice::WriteOnly);
    silo_file.open(QIODevice::WriteOnly);

    QJsonDocument user_doc(user_obj);
    QJsonDocument wheat_land_doc(wheat_land_obj);
    QJsonDocument alfalfa_land_doc(alfalfa_land_obj);
    QJsonDocument aviculture_doc(aviculture_obj);
    QJsonDocument livestock_doc(livestock_obj);
    QJsonDocument aghol_doc(aghol_obj);
    QJsonDocument store_doc(store_obj);
    QJsonDocument silo_doc(silo_obj);

    user_file.write(user_doc.toJson());
    wheat_land_file.write(wheat_land_doc.toJson());
    alfalfa_land_file.write(alfalfa_land_doc.toJson());
    aviculture_file.write(aviculture_doc.toJson());
    livestock_file.write(livestock_doc.toJson());
    aghol_file.write(aghol_doc.toJson());
    store_file.write(store_doc.toJson());
    silo_file.write(silo_doc.toJson());

    user_file.flush();
    wheat_land_file.flush();
    alfalfa_land_file.flush();
    aviculture_file.flush();
    livestock_file.flush();
    aghol_file.flush();
    store_file.flush();
    silo_file.flush();

    user_file.close();
    wheat_land_file.close();
    alfalfa_land_file.close();
    aviculture_file.close();
    livestock_file.close();
    aghol_file.close();
    store_file.close();
    silo_file.close();
}
