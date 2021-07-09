#include "WheatLand.h"
#include "ui_WheatLand.h"

WheatLand::WheatLand(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WheatLand)
{
    ui->setupUi(this);
}

WheatLand::~WheatLand()
{
    delete ui;
}
