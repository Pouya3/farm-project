#include "menupage.h"
#include "ui_menupage.h"
#include "rankingpage.h"
#include "file_functions.h"

MenuPage::MenuPage(User* _user, MainPage* _mainpage, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuPage)
{
    ui->setupUi(this);
    this->setFixedSize(830,550);

    user = _user;
    mainpage = _mainpage;

    ui->label->setText(user->Get_username());
    ui->label_5->setText(QString::number(user->Get_level()));
    ui->label_3->setText(QString::number(user->Get_coin()));
    ui->label_4->setText(QString::number(user->Get_experience()));
    ui->label_2->setText(QString::number(user->Get_time()));

    users_for_ranking = Get_users_for_ranking();

    QMultiMap<int, QString>::iterator user_iter;
    user_iter = users_for_ranking.begin();
    int i;
    for(i = 0; i<users_for_ranking.size(); i++){
        if(user_iter.value() == user->Get_username()){
            break;
        }

        user_iter++;
    }
    ui->pushButton_3->setText(QString::number(i+1));

}

MenuPage::~MenuPage()
{
    delete ui;
}

void MenuPage::on_pushButton_3_clicked()
{
    RankingPage* r=new RankingPage(user, users_for_ranking);
    r->show();
}
void MenuPage::on_pushButton_2_clicked()
{
    mainpage->Time_function();
}

void MenuPage::on_pushButton_clicked()
{
    Save_user(user);
    this->close();
    mainpage->close();
}

