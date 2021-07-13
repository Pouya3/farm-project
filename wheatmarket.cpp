#include "wheatmarket.h"
#include "ui_wheatmarket.h"

WheatMarket::WheatMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WheatMarket)
{
    ui->setupUi(this);
    setFixedSize(1000,570);
}

WheatMarket::~WheatMarket()
{
    delete ui;
}
