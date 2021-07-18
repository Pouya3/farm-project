#include "mainpage.h"
#include "ui_mainpage.h"
#include "storepage.h"
#include "livestockpage.h"
#include "alfalfa_landpage.h"
#include "wheat_landpage.h"
#include "agholpage.h"
#include <QMovie>
#include "marketpage.h"
#include "silopage.h"
#include "menupage.h"
#include "aviculturepage.h"
#include "file_functions.h"
#include <vector>
#include <cmath>

MainPage::MainPage(User* _user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setFixedSize(1265,540);
    setWindowTitle("Hay Night");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    QMovie* movie=new QMovie("../farm-project/windmill.gif");
    QMovie* movie2=new QMovie("../farm-project/ch-3.gif");
    QMovie* movie3=new QMovie("../farm-project/dog1.gif");
    QMovie* movie4=new QMovie("../farm-project/hen.gif");
    ui->label_3->setMovie(movie3);
    ui->label->setMovie(movie);
    ui->label_2->setMovie(movie2);
    ui->label_4->setMovie(movie4);
    movie->start();
    movie2->start();
    movie3->start();
    movie4->start();
    user = _user;

    //user->Set_coin(50000);

    timer=new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Time_function()));
    timer->start(300000);

    saving_tiemer = new QTimer(this);
    saving_tiemer->start(10);
    connect(saving_tiemer, SIGNAL(timeout()), this, SLOT(Save_this_user()));
}

MainPage:: ~MainPage()
{
    Save_user(user);
    delete ui;
}

void MainPage:: on_pushButton_a_clicked()
{
    StorePage* s=new StorePage(user->store);
    s->show();
}


void MainPage:: on_pushButton_a_8_clicked()
{
    LivestockPage* l=new LivestockPage(user->livestock);
    l->show();
}


void MainPage:: on_pushButton_a_5_clicked()
{
    Alfalfa_landPage* a=new Alfalfa_landPage(user->alfalfa_land);
    a->show();
}


void MainPage:: on_pushButton_a_6_clicked()
{
    Wheat_landPage* w=new Wheat_landPage(user->wheat_land);
    w->show();
}


void MainPage:: on_pushButton_a_7_clicked()
{
    SiloPage* s=new SiloPage(user->silo);
    s->show();
}


void MainPage::on_pushButton_a_4_clicked()
{
    AviculturePage* a=new AviculturePage(user->aviculture);
    a->show();
}


void MainPage:: on_pushButton_a_3_clicked()
{
    AgholPage* a=new AgholPage(user->aghol);
    a->show();
}


void MainPage:: on_pushButton_mm_2_clicked()
{
    MenuPage* m=new MenuPage(user, this);
    m->show();
}
void MainPage:: Time_function(){
    std::vector<std::pair<int,int>> milk_vect;
    std::vector<std::pair<int, int>>::iterator milk_iter;
    milk_vect = user->store->Get_milk_info();
    milk_iter = milk_vect.begin();

    user->Set_time(user->Get_time()+1);
    user->Set_experience(user->Get_experience()+1);
    if(user->aghol->Get_feeding_timer()>0){
        user->aghol->Set_feeding_timer(user->aghol->Get_feeding_timer()-1);
        if(user->aghol->Get_feeding_timer()==0)
            user->aghol->Set_feeding_status(2);
    }
    if(user->aviculture->Get_feeding_timer()>0){
        user->aviculture->Set_feeding_timer(user->aviculture->Get_feeding_timer()-1);
        if(user->aviculture->Get_feeding_timer()==0)
            user->aviculture->Set_feeding_status(2);
    }
    if(user->livestock->Get_feeding_timer()>0){
        user->livestock->Set_feeding_timer(user->livestock->Get_feeding_timer()-1);
        if(user->livestock->Get_feeding_timer()==0)
            user->livestock->Set_feeding_status(2);
    }
    if(user->aghol->Get_building_timer()>0){
        user->aghol->Set_building_timer(user->aghol->Get_building_timer()-1);
        if(user->aghol->Get_building_timer()==0){
            user->aghol->Set_building_status(2);
            user->aghol->Set_level(1);
            user->aghol->Set_total_storage(2);
            user->Set_experience(user->Get_experience()+20);
        }
    }
    if(user->aviculture->Get_building_timer()>0){
        user->aviculture->Set_building_timer(user->aviculture->Get_building_timer()-1);
        if(user->aviculture->Get_building_timer()==0){
            user->aviculture->Set_building_status(2);
            user->aviculture->Set_level(1);
            user->aviculture->Set_total_storage(2);
            user->Set_experience(user->Get_experience()+5);
        }
    }
    if(user->livestock->Get_building_timer()>0){
        user->livestock->Set_building_timer(user->livestock->Get_building_timer()-1);
        if(user->livestock->Get_building_timer()==0){
            user->livestock->Set_building_status(2);
            user->livestock->Set_level(1);
            user->livestock->Set_total_storage(2);
            user->Set_experience(user->Get_experience()+10);
        }
    }
    if(user->aghol->Get_upgrade_timer()>0){
        user->aghol->Set_upgrade_timer(user->aghol->Get_upgrade_timer()-1);
        if(user->aghol->Get_upgrade_timer()==0){
        user->aghol->Set_level(user->aghol->Get_level()+1);
        user->aghol->Set_total_storage(user->aghol->Get_total_storage()*2);
        user->Set_experience(user->Get_experience()+15);
        }
    }
    if(user->aviculture->Get_upgrade_timer()>0){
        user->aviculture->Set_upgrade_timer(user->aviculture->Get_upgrade_timer()-1);
        if(user->aviculture->Get_upgrade_timer()==0){
        user->aviculture->Set_level(user->aviculture->Get_level()+1);
        user->aviculture->Set_total_storage(user->aviculture->Get_total_storage()*2);
        user->Set_experience(user->Get_experience()+5);
        }
    }
    if(user->livestock->Get_upgrade_timer()>0){
        user->livestock->Set_upgrade_timer(user->livestock->Get_upgrade_timer()-1);
        if(user->livestock->Get_upgrade_timer()==0){
        user->livestock->Set_level(user->livestock->Get_level()+1);
        user->livestock->Set_total_storage(user->livestock->Get_total_storage()*2);
        user->Set_experience(user->Get_experience()+6);
        }
    }
    if(user->store->Get_upgrade_timer()>0){
        user->store->Set_upgrade_timer(user->store->Get_upgrade_timer()-1);
        if(user->store->Get_upgrade_timer()==0){
            user->Set_experience(user->Get_experience()+(user->store->Get_level()*3));
            user->store->Set_level(user->store->Get_level()+1);
            user->store->Set_total_storage(ceil(user->store->Get_total_storage()*1.5));
        }
    }
    while(milk_iter != milk_vect.end()){
        (milk_iter->second)--;
        if(milk_iter->second == 0){
            user->store->Delete(5, milk_iter->first);

            milk_vect.erase(milk_iter);
            milk_iter = milk_vect.begin();
        }
        else {
            user->store->Set_milk_info(milk_vect);

            milk_iter++;
        }
    }
    if(user->silo->Get_upgrade_timer()>0){
        user->silo->Set_upgrade_timer(user->silo->Get_upgrade_timer()-1);
        if(user->silo->Get_upgrade_timer()==0){
            user->Set_experience(user->Get_experience()+(user->silo->Get_level()*2));
            user->silo->Set_level(user->silo->Get_level()+1);
            user->silo->Set_total_storage(user->silo->Get_total_storage()*2);
        }
    }
    if(user->wheat_land->Get_ripening_timer()>0){
        user->wheat_land->Set_ripening_timer(user->wheat_land->Get_ripening_timer()-1);
        if(user->wheat_land->Get_ripening_timer()==0){
           user->wheat_land->Set_cultivation_status(2);
        }
    }
    if(user->alfalfa_land->Get_ripening_timer()>0){
        user->alfalfa_land->Set_ripening_timer(user->alfalfa_land->Get_ripening_timer()-1);
        if(user->alfalfa_land->Get_ripening_timer()==0){
            user->alfalfa_land->Set_cultivation_status(3);
            user->alfalfa_land->Set_total_area(user->alfalfa_land->Get_total_area()*2);
          }
    }
    if(user->alfalfa_land->Get_upgrade_timer()>0){
        user->alfalfa_land->Set_upgrade_timer(user->alfalfa_land->Get_upgrade_timer()-1);
        if(user->alfalfa_land->Get_upgrade_timer()==0){
            user->Set_experience(user->Get_experience()+3);
            user->alfalfa_land->Set_level(user->alfalfa_land->Get_level()+1);
            user->alfalfa_land->Set_total_area(user->alfalfa_land->Get_total_area()*2);
        }
    }
    if(user->wheat_land->Get_upgrade_timer()>0){
        user->wheat_land->Set_upgrade_timer(user->wheat_land->Get_upgrade_timer()-1);
        if(user->wheat_land->Get_upgrade_timer()==0){
            user->Set_experience(user->Get_experience()+3);
            user->wheat_land->Set_level(user->wheat_land->Get_level()+1);
            user->wheat_land->Set_total_area(user->wheat_land->Get_total_area()*2);
        }
    }
    if(user->alfalfa_land->Get_building_timer()>0){
        user->alfalfa_land->Set_building_timer(user->alfalfa_land->Get_building_timer()-1);
        if(user->alfalfa_land->Get_building_timer()==0){
            user->alfalfa_land->Set_building_status(2);
            user->Set_experience(user->Get_experience()+6);
            user->alfalfa_land->Set_total_area(4);
            user->alfalfa_land->Set_level(1);
        }
    }
    if(user->alfalfa_land->Get_plowing_timer()>0){
        user->alfalfa_land->Set_plowing_timer(user->alfalfa_land->Get_plowing_timer()-1);
        if(user->alfalfa_land->Get_plowing_timer()==0){
            user->alfalfa_land->Set_cultivation_status(1);
            user->Set_experience(user->Get_experience()+user->alfalfa_land->Get_plowed_area());
        }
    }

}

void MainPage::on_pushButton_a_2_clicked()
{
    MarketPage* m=new MarketPage(user, user->store, user->aghol, user->livestock, user->aviculture, user->silo);
    m->show();
}

void MainPage::Save_this_user(){
    Save_user(user);
}
