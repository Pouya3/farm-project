#include "sheepmarket.h"
#include "ui_sheepmarket.h"

SheepMarket::SheepMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SheepMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);

    ui->label->setText(QString::number(aghol->Get_used_storage()));
    ui->label_2->setText(QString::number(aghol->Get_total_storage() - aghol->Get_used_storage()));
}

SheepMarket::~SheepMarket()
{
    delete ui;
}

void SheepMarket::on_pushButton_clicked()//1 -> buy                 2 -> sell
{
    if(aghol->Get_building_status() != 2){
        //qmessagebox --> "you must build livestock to buy or sell sheep"
    }
    else{
        if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
            //qmessagebox --> "number of buying and selling items is 0"
            return;
        }

        if(ui->spinBox_2->text().toInt() != 0){                                                                     //
            if(aghol->Get_used_storage() < ui->spinBox_2->text().toInt()){                                          //
                //qmessagebox --> "not enough sheep to sell"                                                        //
            }                                                                                                       //
            else{                                                                                                   // sell
                aghol->Delete(1, ui->spinBox_2->text().toInt());                                                    //
                user->Set_coin(user->Get_coin() + ui->spinBox_2->text().toInt()*70);                                //
            }                                                                                                       //
        }

        if(ui->spinBox->text().toInt() != 0){                                                                       //
            if(aghol->Get_total_storage() - aghol->Get_used_storage() < ui->spinBox->text().toInt()){               //
                //qmessagebox --> "not enough space in aghol"                                                       //
            }                                                                                                       //
            else{                                                                                                   // buy
                aghol->Add(1, ui->spinBox->text().toInt());                                                         //
                user->Set_coin(user->Get_coin() - ui->spinBox->text().toInt()*80);                                  //
                user->Set_experience(user->Get_experience() + 15);                                                  //
            }                                                                                                       //
        }                                                                                                           //
    }
}

