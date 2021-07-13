#include "shovel_market.h"
#include "ui_shovel_market.h"

Shovel_market::Shovel_market(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Shovel_market)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);
}

Shovel_market::~Shovel_market()
{
    delete ui;
}
