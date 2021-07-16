#include "loadingpage.h"
#include "ui_loadingpage.h"
#include "loginpage.h"
#include <QMovie>
#include "mainpage.h"
#include <iostream>

LoadingPage::LoadingPage(User* _user, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadingPage)
{
//    int a=0;
    ui->setupUi(this);
    this->setFixedSize(750,450);
    QMovie* movie=new QMovie("../farm-project/rr.gif");
    ui->label->setMovie(movie);
    movie->start();
/*    if(a==0) {

        LoginPage* l=new LoginPage;
        l->show();
        this->close();
    }
*/

    user = _user;

    timer = new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(close_this()));
    timer->start(6000);
}

void LoadingPage::changing()
{

}

LoadingPage::~LoadingPage()
{
    delete ui;
}

void LoadingPage::close_this(){
    MainPage* m = new MainPage(user);
    m->show();

    timer->stop();
    this->close();
}
