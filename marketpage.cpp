#include "marketpage.h"
#include "ui_marketpage.h"

MarketPage::MarketPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarketPage)
{
    ui->setupUi(this);
    this->setFixedSize(970,685);
}

MarketPage::~MarketPage()
{
    delete ui;
}
