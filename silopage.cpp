#include "silopage.h"
#include "ui_silopage.h"

SiloPage::SiloPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SiloPage)
{
    ui->setupUi(this);
    this->setFixedSize(1000,660);
}

SiloPage::~SiloPage()
{
    delete ui;
}
