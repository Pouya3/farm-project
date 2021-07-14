#include "wheatmarket.h"
#include "ui_wheatmarket.h"

WheatMarket::WheatMarket(User* _user, Silo* _silo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WheatMarket)
{
    ui->setupUi(this);
    setFixedSize(1000,570);

    user = _user;
    silo = _silo;

    ui->label->setText(QString::number(silo->Get_used_storage()));
    ui->label->setText(QString::number(silo->Get_total_storage() - silo->Get_used_storage()));
}

WheatMarket::~WheatMarket()
{
    delete ui;
}

void WheatMarket::on_pushButton_clicked() // 1 --> buy              2 --> sell
{
    if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
        // qmessagebox --> "number of buying and selling items is 0"
        QMessageBox::critical(this,"ZERO","Number of buying and selling items is 0");
        return;
    }

    if(ui->spinBox_2->text().toInt() != 0){                                                         //
        if(user->Get_level() >= 3){                                                               //
            if(silo->Get_used_storage() < ui->spinBox_2->text().toInt()){                           //
                //qmessagbox --> "not enough wheats to sell"                                      //
            QMessageBox::critical(this,"NOT ENOUGH WHEATS","Not enough wheats to sell");          //
            }                                                                                     //
            else{                                                                                 //
                silo->Delete(1, ui->spinBox_2->text().toInt());                                     //
                user->Set_coin(user->Get_coin() + ui->spinBox_2->text().toInt()*2);                 //
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*6);   // sell
            }                                                                                     //
        }                                                                                         //
        else{                                                                                     //
            //qmessagebox --> "you must reach level 3 to sell stuff"                              //
            QMessageBox::critical(this,"LEVEL","you must reach level 3 to sell stuff");           //
        }                                                                                         //
    }                                                                                             //

    if(ui->spinBox->text().toInt() != 0){ // buy                                                    //
        if(user->Get_level() >= 2){                                                                   //
            if(silo->Get_total_storage() - silo->Get_used_storage() < ui->spinBox->text().toInt()){ //
                //qmessagebox --> "not enough space in silo"                                          //
                QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in silo");            //
            }                                                                                         //
            else{                                                                                     //
                silo->Add(1, ui->spinBox->text().toInt());                                          //
                user->Set_coin(user->Get_coin() - ui->spinBox->text().toInt()*1);                   // buy
                user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*2);       //
            }                                                                                         //
        }                                                                                             //
        else{                                                                                         //
            //qmessagebox --> "you must reach level 2 to buy stuff"                                   //
            QMessageBox::critical(this,"LEVEL","you must reach level 2 to buy stuff");                //
        }                                                                                             //
    }                                                                                                 //
}

