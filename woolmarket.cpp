#include "woolmarket.h"
#include "ui_woolmarket.h"

WoolMarket::WoolMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WoolMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);
}

WoolMarket::~WoolMarket()
{
    delete ui;
}
