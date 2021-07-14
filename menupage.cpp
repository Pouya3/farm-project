#include "menupage.h"
#include "ui_menupage.h"
<<<<<<< HEAD
#include "rankingpage.h"
=======
#include "file_functions.h"
>>>>>>> 8c6eb99a17f2a0eae3dd5f19c98a840d82d207aa

MenuPage::MenuPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuPage)
{
    ui->setupUi(this);
    this->setFixedSize(830,550);

    ui->label->setText(user->Get_username());
    ui->label_5->setText(QString::number(user->Get_level()));
    ui->label_3->setText(QString::number(user->Get_coin()));
    ui->label_4->setText(QString::number(user->Get_experience()));
    ui->label_2->setText(QString::number(user->Get_time()));
}

MenuPage::~MenuPage()
{
    delete ui;
}

<<<<<<< HEAD
void MenuPage::on_pushButton_3_clicked()
{
    RankingPage* r=new RankingPage;
    r->show();

=======
void MenuPage::on_pushButton_2_clicked()
{
    mainpage->Time_function();
}

void MenuPage::on_pushButton_clicked()
{
    Save_user(user);
    this->close();
    mainpage->close();
>>>>>>> 8c6eb99a17f2a0eae3dd5f19c98a840d82d207aa
}

