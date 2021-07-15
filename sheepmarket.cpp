#include "sheepmarket.h"
#include "ui_sheepmarket.h"

SheepMarket::SheepMarket(User* _user, Aghol* _aghol, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SheepMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);

    user = _user;
    aghol = _aghol;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

SheepMarket::~SheepMarket()
{
    delete ui;
}

void SheepMarket::on_pushButton_clicked()//1 -> buy                 2 -> sell
{
    if(aghol->Get_building_status() != 2){
        //qmessagebox --> "you must build aghol to buy or sell sheep"
        QMessageBox::critical(this,"NOT BUILT","you must build aghol to buy or sell sheep");
    }
    else{
        if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
            //qmessagebox --> "number of buying and selling items is 0"
            QMessageBox::critical(this,"0 VALUE","number of buying and selling items is 0");
            return;
        }

        if((ui->spinBox->text().toInt() != 0)&&(ui->spinBox_2->text().toInt() != 0)){
            // qmessagebox --> "you cannot buy and sell at the same time"
            QMessageBox::critical(this,"BUY AND SELL","you cannot buy and sell at the same time");
            return;
        }

        if(ui->spinBox_2->text().toInt() != 0){                                                                     //
            if(aghol->Get_used_storage() < ui->spinBox_2->text().toInt()){                                          //
                //qmessagebox --> "not enough sheep to sell"                                                        //
                QMessageBox::critical(this,"NOT ENOUGH SHEEP","not enough sheep to sell");                          //
            }                                                                                                       //
            else{                                                                                                   // sell
                aghol->Delete(1, ui->spinBox_2->text().toInt());                                                    //
                user->Set_coin(user->Get_coin() + ui->spinBox_2->text().toInt()*70);                                //
                 user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*6);                    //
            }                                                                                                       //
        }                                                                                                           //

        if(ui->spinBox->text().toInt() != 0){                                                                       //
            if(user->Get_coin() < ui->spinBox->text().toInt()*80){                                                  //
                //qmessagebox --> "not enough coins to buy this number of sheep"                                    //
                QMessageBox::critical(this,"NOT ENOUGH COINS","not enough coins to buy this number of sheep");      //
            }                                                                                                       //
            else{                                                                                                   //
                if(aghol->Get_total_storage() - aghol->Get_used_storage() < ui->spinBox->text().toInt()){           //
                    //qmessagebox --> "not enough space in aghol"                                                   //
                    QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in aghol");                     // buy
                }                                                                                                   //
                else{                                                                                               //
                    aghol->Add(1, ui->spinBox->text().toInt());                                                     //
                    user->Set_coin(user->Get_coin() - ui->spinBox->text().toInt()*80);                              //
                    user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*2);                   //
                }                                                                                                   //
            }                                                                                                       //
        }                                                                                                           //
    }
}

void SheepMarket::Set_values(){
    ui->label->setText(QString::number(aghol->Get_used_storage()));
    ui->label_2->setText(QString::number(aghol->Get_total_storage() - aghol->Get_used_storage()));
}
