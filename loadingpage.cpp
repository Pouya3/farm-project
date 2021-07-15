#include "loadingpage.h"
#include "ui_loadingpage.h"
#include "loginpage.h"
#include <iostream>

LoadingPage::LoadingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadingPage)
{
    int a=0;
    ui->setupUi(this);
    this->setFixedSize(750,450);
    if(a==0) {

        LoginPage* l=new LoginPage;
        l->show();
        this->close();
    }

}

void LoadingPage::changing()
{

}

LoadingPage::~LoadingPage()
{
    delete ui;
}
