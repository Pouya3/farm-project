#include "rankingpage.h"
#include "ui_rankingpage.h"

RankingPage::RankingPage(User* _user, QMultiMap<int, QString> _users_fot_ranking, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RankingPage)
{
    ui->setupUi(this);
    this->setFixedSize(490,640);

    users_for_ranking = _users_fot_ranking;
    user = _user;

    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Rank"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Username"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Experience"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Level"));

    QMultiMap<int, QString>::iterator user_iter;
    user_iter = users_for_ranking.begin();

    ui->label_2->setText(user_iter.value());

    user_iter++;
    if(user_iter != users_for_ranking.end()){
        ui->label_3->setText(user_iter.value());

        user_iter++;
        if(user_iter != users_for_ranking.end()){
            ui->label->setText(user_iter.value());
        }
        else{
            ui->label->setText("N/A");
        }
    }
    else{
        ui->label_3->setText("N/A");
        ui->label->setText("N/A");
    }

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(users_for_ranking.size());

    user_iter = users_for_ranking.begin();
    int level;
    int exp;
    int i;

    ui->tableWidget->verticalHeader()->hide();//hide left headers!
    for(i = 0; i<users_for_ranking.size(); i++){

        exp = user_iter.key();
        level = 1;
        while(exp >= 10){
            exp -= 10;
            exp /= 2;

            level++;
        }


       ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
       ui->tableWidget->setItem(i, 1, new QTableWidgetItem(user_iter.value()));
       ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(user_iter.key())));
       ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(level)));


        if(user_iter.value() == user->Get_username()){
            // color the row;
            ui->tableWidget->item(i,0)->setBackground(QBrush(QColor(250,187,61)));//color background my row
            ui->tableWidget->item(i,1)->setBackground(QBrush(QColor(250,187,61)));//color background my row
            ui->tableWidget->item(i,2)->setBackground(QBrush(QColor(250,187,61)));//color background my row
            ui->tableWidget->item(i,3)->setBackground(QBrush(QColor(250,187,61)));//color background my row
        }

        user_iter++;
    }
}

RankingPage::~RankingPage()
{
    delete ui;
}
