#include "livestockpage.h"
#include "ui_livestockpage.h"

LivestockPage::LivestockPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LivestockPage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
}

LivestockPage::~LivestockPage()
{
    delete ui;
}
