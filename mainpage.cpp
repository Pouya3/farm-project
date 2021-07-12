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
    if(user->Aghol->Get_feeding_timer()>0){
        user->Aghol->Set_feeding_timer(Get_feeding_timer()-1);
    }
}

void MainPage::on_pushButton_a_2_clicked()
{
    MarketPage* m=new MarketPage;
    m->show();
}

