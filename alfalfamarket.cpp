#include "alfalfamarket.h"
#include "ui_alfalfamarket.h"

AlfalfaMarket::AlfalfaMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlfalfaMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);

    ui->label->setText(QString::number(store->Get_object(3)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}

AlfalfaMarket::~AlfalfaMarket()
{
    delete ui;
}

void AlfalfaMarket::on_pushButton_clicked()
{
    if(user->Get_level() < 3){
        //qmessagebox --> "you cannot buy alfalfa until level 3"
    }
    else{
        if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
            // qmessagebox --> "number of buying and selling items is 0"
            return;
        }

        if(ui->spinBox->text().toInt() != 0){                                            //
            if(store->Get_object(3) < ui->spinBox->text().toInt()){                      //
                //qmessagbox --> "not enough alfalfa to sell"                            //
            }                                                                            // sell
            else{                                                                        //
                store->Delete(3, ui->spinBox->text().toInt());                           //
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*4);        //
            }                                                                            //
        }                                                                                //

        if(ui->spinBox_2->text().toInt() != 0){ // buy                                                   //
            if(store->Get_total_storage() - store->Get_used_storage() < ui->spinBox_2->text().toInt()){  //
                //qmessagebox --> "not enough alfalfa"                                                   //
            }                                                                                            //
            else{                                                                                        //
                store->Add(3, ui->spinBox_2->text().toInt());                                            // buy
                user->Set_coin(user->Get_coin() - ui->spinBox_2->text().toInt()*6);                      //
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*2);          //
            }                                                                                            //
        }                                                                                                //
    }
}

