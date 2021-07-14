#include "spacepage_2.h"
#include "ui_spacepage_2.h"

SpacePage_2::SpacePage_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpacePage_2)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
}

SpacePage_2::~SpacePage_2()
{
    delete ui;
}
