#include "nailmarket.h"
#include "ui_nailmarket.h"

NailMarket::NailMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NailMarket)
{
    ui->setupUi(this);
    setFixedSize(1000,570);
}

NailMarket::~NailMarket()
{
    delete ui;
}
