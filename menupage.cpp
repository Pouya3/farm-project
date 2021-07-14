#include "menupage.h"
#include "ui_menupage.h"
#include "rankingpage.h"

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

void MenuPage::on_pushButton_3_clicked()
{
    RankingPage* r=new RankingPage;
    r->show();

}

