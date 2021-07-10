#include "signuppage.h"
#include "ui_signuppage.h"

signupPage::signupPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signupPage)
{
    ui->setupUi(this);
    this->setFixedSize(880,600);
}

signupPage::~signupPage()
{
    delete ui;
}
