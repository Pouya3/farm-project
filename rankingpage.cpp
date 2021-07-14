#include "rankingpage.h"
#include "ui_rankingpage.h"

RankingPage::RankingPage(User* _user, QMultiMap<int, QString> _users_fot_ranking, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RankingPage)
{
    ui->setupUi(this);
    this->setFixedSize(490,640);

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));

    users_for_ranking = _users_fot_ranking;
    user = _user;
}

RankingPage::~RankingPage()
{
    delete ui;
}

void RankingPage::Set_values(){
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Rank"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Username"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Experience"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Level"));

    ui->tableWidget->clear();

    QMultiMap<int, QString>::iterator user_iter;
    user_iter = users_for_ranking.end();
    user_iter--;

    ui->label_2->setText(user_iter.value());

    user_iter--;
    if(user_iter != users_for_ranking.begin() - 1){
        ui->label_3->setText(user_iter.value());

        user_iter--;
        if(user_iter != users_for_ranking.begin() - 1){
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

    user_iter = users_for_ranking.end();
    user_iter--;
    int level;
    int exp;
    int i;
    int rank = 1;
    int number_of_same_rankers = 0;

    ui->tableWidget->verticalHeader()->hide();//hide left headers!
    for(i = 0; i<users_for_ranking.size(); i++){

        exp = user_iter.key();
        level = 1;
        while(exp >= 10){
            exp -= 10;
            exp /= 2;

            level++;
        }

        if((user_iter + 1) != users_for_ranking.end()){
            if(user_iter.key() < (user_iter + 1).key()){
                rank += number_of_same_rankers;
                number_of_same_rankers = 0;
            }
        }

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(rank)));
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

        user_iter--;
        number_of_same_rankers++;
    }
}
