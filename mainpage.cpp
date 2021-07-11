#include "mainpage.h"
#include "ui_mainpage.h"
#include "storepage.h"
#include "livestockpage.h"
#include "alfalfa_landpage.h"
#include "wheat_landpage.h"
#include "agholpage.h"
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
    timer->start(15000);
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
    Time time;
    time=user->Get_time();
    time.Set_hour(user->Get_time().Get_hour()+1);
    user->Set_time(time);

}
