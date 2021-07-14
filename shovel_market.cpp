#include "shovel_market.h"
#include "ui_shovel_market.h"

Shovel_market::Shovel_market(User* _user, Store* _store, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Shovel_market)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);

    user = _user;
    store = _store;

    ui->label->setText(QString::number(store->Get_object(1)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}

Shovel_market::~Shovel_market()
{
    delete ui;
}

void Shovel_market::on_pushButton_clicked()// 1 --> sell              2 --> buy
{
    if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
        // qmessagebox --> "number of buying and selling items is 0"
        QMessageBox::critical(this,"0 VALUE","number of buying and selling items is 0");
        return;
    }

    if(ui->spinBox->text().toInt() != 0){                                                         //
        if(user->Get_level() >= 3){                                                               //
            if(store->Get_object(1) < ui->spinBox->text().toInt()){                               //
                //qmessagbox --> "not enough shovels to sell"                                     //
                QMessageBox::critical(this,"NOT ENOUGH SHOVELS","not enough shovels to sell");    //
            }                                                                                     // sell
            else{                                                                                 //
                store->Delete(1, ui->spinBox->text().toInt());                                    //
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*30);                //
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*6);   //
            }                                                                                     //
        }                                                                                         //
        else{                                                                                     //
            //qmessagebox --> "you must reach level 3 to sell stuff"                              //
            QMessageBox::critical(this,"LEVEL","you must reach level 3 to sell stuff");           //
        }                                                                                         //
    }                                                                                             //

    if(ui->spinBox_2->text().toInt() != 0){ // buy
        if(user->Get_level() >= 2){
            if(store->Get_total_storage() - store->Get_used_storage() < ui->spinBox_2->text().toInt()){  //
                //qmessagebox --> "not enough space in store"                                            //
                QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in store");              //
            }                                                                                            //
            else{                                                                                        //
                store->Add(1, ui->spinBox_2->text().toInt());                                            // buy
                user->Set_coin(user->Get_coin() - ui->spinBox_2->text().toInt()*50);                     //
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*2);          //
            }                                                                                            //
        }                                                                                                //
        else{                                                                                            //
            //qmessagebox --> "you must reach level 2 to buy stuff"                                      //
            QMessageBox::critical(this,"LEVEL","you must reach level 2 to buy stuff");                             //
        }                                                                                                //
    }                                                                                                    //
}

