#include "wheatmarket.h"
#include "ui_wheatmarket.h"

WheatMarket::WheatMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WheatMarket)
{
    ui->setupUi(this);
    setFixedSize(1000,570);

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

    if(ui->spinBox->text().toInt() != 0){                                          //
        if(silo->Get_used_storage() < ui->spinBox->text().toInt()){                //
            //qmessagbox --> "not enough wheats to sell"                           //
        QMessageBox::critical(this,"LESS","Not enough wheats to sell");            //
        }                                                                          //
        else{                                                                      // sell
            silo->Delete(1, ui->spinBox->text().toInt());                          //
            user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*2);      //
        }                                                                          //
    }                                                                              //

    if(ui->spinBox_2->text().toInt() != 0){ // buy                                                 //
        if(silo->Get_total_storage() - silo->Get_used_storage() < ui->spinBox_2->text().toInt()){  //
            //qmessagebox --> "not enough wheats"                                                  //
        QMessageBox::critical(this,"LESS","Not enough wheats");                                    //
        }                                                                                          //
        else{                                                                                      //
            silo->Add(1, ui->spinBox_2->text().toInt());                                           // buy
            user->Set_coin(user->Get_coin() - ui->spinBox_2->text().toInt()*1);                    //
            user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*8);        //
        }                                                                                          //
    }
}

