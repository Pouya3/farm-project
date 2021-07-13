#include "rankingpage.h"
#include "ui_rankingpage.h"

RankingPage::RankingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RankingPage)
{
    ui->setupUi(this);
    this->setFixedSize(490,640);
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
    }

    QTableWidgetItem table_item;

    user_iter = users_for_ranking.begin();
    int level;
    int exp;
    for(int i=0; i<users_for_ranking.size(); i++){

        exp = user_iter.key();
        level = 1;
        while(exp >= 10){
            exp -= 10;
            exp /= 2;

            level++;
        }


        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(i+1));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(user_iter.value()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(user_iter.key()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(level));

        if(user_iter.value() == user->Get_username()){
            // color the row;
        }
    }
}

RankingPage::~RankingPage()
{
    delete ui;
}
