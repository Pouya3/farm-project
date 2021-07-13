#include "woolpage.h"
#include "ui_woolpage.h"

WoolPage::WoolPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WoolPage)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);
}

WoolPage::~WoolPage()
{
    delete ui;
}
