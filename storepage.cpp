#include "storepage.h"
#include "ui_storepage.h"

StorePage::StorePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StorePage)
{
    ui->setupUi(this);
    this->setFixedSize(1200,600);
}

StorePage::~StorePage()
{
    delete ui;
}
