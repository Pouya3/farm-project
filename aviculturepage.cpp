#include "aviculturepage.h"
#include "ui_aviculturepage.h"

AviculturePage::AviculturePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AviculturePage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
}

AviculturePage::~AviculturePage()
{
    delete ui;
}
