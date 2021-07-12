#include "menupage.h"
#include "ui_menupage.h"

MenuPage::MenuPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuPage)
{
    ui->setupUi(this);
    this->setFixedSize(830,550);
}

MenuPage::~MenuPage()
{
    delete ui;
}
