#include "loadingpage.h"
#include "ui_loadingpage.h"
#include <iostream>

LoadingPage::LoadingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadingPage)
{
    ui->setupUi(this);
    this->setFixedSize(750,450);

}

void LoadingPage::changing()
{

}

LoadingPage::~LoadingPage()
{
    delete ui;
}
