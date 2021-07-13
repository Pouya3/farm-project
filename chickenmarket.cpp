#include "chickenmarket.h"
#include "ui_chickenmarket.h"

ChickenMarket::ChickenMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChickenMarket)
{
    ui->setupUi(this);
    setFixedSize(1000,570);
}

ChickenMarket::~ChickenMarket()
{
    delete ui;
}
