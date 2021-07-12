#include "agholpage.h"
#include "ui_agholpage.h"

AgholPage::AgholPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AgholPage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
}

AgholPage::~AgholPage()
{
    delete ui;
}
