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

MarketPage::MarketPage(User* _user, Store* _store, Aghol* _aghol, Livestock* _livestock, Aviculture* _aviculture, Silo* _silo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarketPage)
{
    ui->setupUi(this);
    this->setFixedSize(970,685);

    user = _user;
    store = _store;
    aghol = _aghol;
    livestock = _livestock;
    aviculture = _aviculture;
    silo = _silo;
}

MarketPage::~MarketPage()
{
    delete ui;
}

void MarketPage::on_pushButton_clicked()
{
    NailMarket* n=new NailMarket(user, store);
    n->show();
}


void MarketPage::on_pushButton_2_clicked()
{
    Shovel_market* s=new Shovel_market(user, store);
    s->show();
}


void MarketPage::on_pushButton_3_clicked()
{
    SheepMarket* s=new SheepMarket(user, aghol);
    s->show();
}


void MarketPage::on_pushButton_4_clicked()
{
    CowMarket* c=new CowMarket(user, livestock);
    c->show();
}


void MarketPage::on_pushButton_5_clicked()
{
    ChickenMarket* c=new ChickenMarket(user, aviculture);
    c->show();
}


void MarketPage::on_pushButton_6_clicked()
{
    AlfalfaMarket* a=new AlfalfaMarket(user, store);
    a->show();
}


void MarketPage::on_pushButton_7_clicked()
{
    WheatMarket* w=new WheatMarket(user, silo);
    w->show();
}


void MarketPage::on_pushButton_8_clicked()
{
    eggMarket* e=new eggMarket(user, store);
    e->show();
}


void MarketPage::on_pushButton_9_clicked()
{
    MilkMarket* m=new MilkMarket(user, store);
    m->show();
}


void MarketPage::on_pushButton_10_clicked()
{
    WoolMarket* w=new WoolMarket(user, store);
    w->show();
}

