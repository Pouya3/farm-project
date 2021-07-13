#include "eggmarket.h"
#include "ui_eggmarket.h"

eggMarket::eggMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eggMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);
}

eggMarket::~eggMarket()
{
    delete ui;
}
