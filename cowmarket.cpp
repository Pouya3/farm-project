#include "cowmarket.h"
#include "ui_cowmarket.h"

CowMarket::CowMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CowMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);
}

CowMarket::~CowMarket()
{
    delete ui;
}
