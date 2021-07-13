#include "sheepmarket.h"
#include "ui_sheepmarket.h"

SheepMarket::SheepMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SheepMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);
}

SheepMarket::~SheepMarket()
{
    delete ui;
}
