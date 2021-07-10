#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setFixedSize(880,600);
}

LoginPage::~LoginPage()
{
    delete ui;
}
