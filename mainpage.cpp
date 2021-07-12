#include "mainpage.h"
#include "ui_mainpage.h"
#include "storepage.h"
#include "livestockpage.h"
#include "alfalfa_landpage.h"
#include "wheat_landpage.h"
#include "agholpage.h"
#include "marketpage.h"
#include "silopage.h"
#include "menupage.h"
#include "aviculturepage.h"
MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->setFixedSize(1265,540);
    timer=new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Time_function()));
    timer->start(300000);
}

MainPage:: ~MainPage()
{
    delete ui;
}

void MainPage:: on_pushButton_a_clicked()
{
    StorePage* s=new StorePage;
    s->show();
}


void MainPage:: on_pushButton_a_8_clicked()
{
    LivestockPage* l=new LivestockPage;
    l->show();
}


void MainPage:: on_pushButton_a_5_clicked()
{
    Alfalfa_landPage* a=new Alfalfa_landPage;
    a->show();
}


void MainPage:: on_pushButton_a_6_clicked()
{
    Wheat_landPage* w=new Wheat_landPage;
    w->show();
}


void MainPage:: on_pushButton_a_7_clicked()
{
    SiloPage* s=new SiloPage;
    s->show();
}


void MainPage::on_pushButton_a_4_clicked()
{
    AviculturePage* a=new AviculturePage;
    a->show();
}


void MainPage:: on_pushButton_a_3_clicked()
{
    AgholPage* a=new AgholPage;
    a->show();
}


void MainPage:: on_pushButton_mm_2_clicked()
{
    MenuPage* m=new MenuPage;
    m->show();
}
void MainPage:: Time_function(){
    user->Set_time(user->Get_time()+1);
    if(user->aghol->Get_feeding_timer()>0){
        user->aghol->Set_feeding_timer(user->aghol->Get_feeding_timer()-1);
    }
    if(user->aviculture->Get_feeding_timer()>0){
        user->aviculture->Set_feeding_timer(user->aviculture->Get_feeding_timer()-1);
    }
    if(user->livestock->Get_feeding_timer()>0){
        user->livestock->Set_feeding_timer(user->livestock->Get_feeding_timer()-1);
    }
    if(user->aghol->Get_building_timer()>0){
        user->aghol->Set_building_timer(user->aghol->Get_building_timer()-1);
    }
    if(user->aviculture->Get_building_timer()>0){
        user->aviculture->Set_building_timer(user->aviculture->Get_building_timer()-1);
    }
    if(user->livestock->Get_building_timer()>0){
        user->livestock->Set_building_timer(user->livestock->Get_building_timer()-1);
    }
    if(user->aghol->Get_upgrade_timer()>0){
        user->aghol->Set_upgrade_timer(user->aghol->Get_upgrade_timer()-1);
    }
    if(user->aviculture->Get_upgrade_timer()>0){
        user->aviculture->Set_upgrade_timer(user->aviculture->Get_upgrade_timer()-1);
    }
    if(user->livestock->Get_upgrade_timer()>0){
        user->livestock->Set_upgrade_timer(user->livestock->Get_upgrade_timer()-1);
    }
    if(user->store->Get_upgrade_timer()>0){
        user->store->Set_upgrade_timer(user->store->Get_upgrade_timer()-1);
    }
    if(user->silo->Get_upgrade_timer()>0){
        user->silo->Set_upgrade_timer(user->silo->Get_upgrade_timer()-1);
    }
    if(user->wheat_land->Get_ripening_timer()>0){
        user->wheat_land->Set_ripening_timer(user->wheat_land->Get_ripening_timer()-1);
    }
    if(user->alfalfa_land->Get_ripening_timer()>0){
        user->alfalfa_land->Set_ripening_timer(user->alfalfa_land->Get_ripening_timer()-1);
    }
    if(user->alfalfa_land->Get_upgrade_timer()>0){
        user->alfalfa_land->Set_upgrade_timer(user->alfalfa_land->Get_upgrade_timer()-1);
    }
    if(user->wheat_land->Get_upgrade_timer()>0){
        user->wheat_land->Set_upgrade_timer(user->wheat_land->Get_upgrade_timer()-1);
    }
    if(user->alfalfa_land->Get_building_timer()>0){
        user->alfalfa_land->Set_building_timer(user->alfalfa_land->Get_building_timer()-1);
    }
    if(user->alfalfa_land->get_plowing_timer()>0){
        user->alfalfa_land->Set_plowing_timer(user->alfalfa_land->get_plowing_timer()-1);
    }
}

void MainPage::on_pushButton_a_2_clicked()
{
    MarketPage* m=new MarketPage;
    m->show();
}

