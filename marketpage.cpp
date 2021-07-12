#include "marketpage.h"
#include "eggmarket.h"
#include "milkmarket.h"
#include "woolmarket.h"
#include "cowmarket.h"
#include "sheepmarket.h"
#include "chickenmarket.h"
#include "nailmarket.h"
#include "wheatmarket.h"
#include "alfalfamarket.h"
#include "shovel_market.h"
#include "ui_marketpage.h"

MarketPage::MarketPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarketPage)
{
    ui->setupUi(this);
    this->setFixedSize(970,685);
}

MarketPage::~MarketPage()
{
    delete ui;
}

void MarketPage::on_pushButton_clicked()
{
    NailMarket* n=new NailMarket;
    n->show();
    this->close();
}


void MarketPage::on_pushButton_2_clicked()
{
    Shovel_market* s=new Shovel_market;
    s->show();
    this->close();
}


void MarketPage::on_pushButton_3_clicked()
{
    SheepMarket* s=new SheepMarket;
    s->show();
    this->close();
}


void MarketPage::on_pushButton_4_clicked()
{
    CowMarket* c=new CowMarket;
    c->show();
    this->close();
}


void MarketPage::on_pushButton_5_clicked()
{
    ChickenMarket* c=new ChickenMarket;
    c->show();
    this->close();
}


void MarketPage::on_pushButton_6_clicked()
{
    AlfalfaMarket* a=new AlfalfaMarket;
    a->show();
    this->close();
}


void MarketPage::on_pushButton_7_clicked()
{
    WheatMarket* w=new WheatMarket;
    w->show();
    this->close();
}


void MarketPage::on_pushButton_8_clicked()
{
    eggMarket* e=new eggMarket;
    e->show();
    this->close();
}


void MarketPage::on_pushButton_9_clicked()
{
    MilkMarket* m=new MilkMarket;
    m->show();
    this->close();
}


void MarketPage::on_pushButton_10_clicked()
{
    WoolMarket* w=new WoolMarket;
    w->show();
    this->close();
}

