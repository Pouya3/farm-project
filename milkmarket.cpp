#include "milkmarket.h"
#include "ui_milkmarket.h"

MilkMarket::MilkMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MilkMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);
}

MilkMarket::~MilkMarket()
{
    delete ui;
}
