#include "alfalfamarket.h"
#include "ui_alfalfamarket.h"

AlfalfaMarket::AlfalfaMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlfalfaMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);
}

AlfalfaMarket::~AlfalfaMarket()
{
    delete ui;
}
