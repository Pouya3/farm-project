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

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
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

    if((ui->spinBox->text().toInt() != 0)&&(ui->spinBox_2->text().toInt() != 0)){
        // qmessagebox --> "you cannot buy and sell at the same time"
        QMessageBox::critical(this,"BUY AND SELL","you cannot buy and sell at the same time");
        return;
    }

    if(ui->spinBox_2->text().toInt() != 0){                                                       //
        if(user->Get_level() >= 2){                                                               //
            if(silo->Get_used_storage() < ui->spinBox_2->text().toInt()){                         //
                //qmessagbox --> "not enough wheats to sell"                                      //
            QMessageBox::critical(this,"NOT ENOUGH WHEATS","Not enough wheats to sell");          //
            }                                                                                     //
            else{                                                                                 //
                silo->Delete(1, ui->spinBox_2->text().toInt());                                   //
                user->Set_coin(user->Get_coin() + ui->spinBox_2->text().toInt()*2);               // sell
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*6);   //
            }                                                                                     //
        }                                                                                         //
        else{                                                                                     //
            //qmessagebox --> "you must reach level 2 to sell stuff"                              //
            QMessageBox::critical(this,"LEVEL","you must reach level 2 to sell stuff");           //
        }                                                                                         //
    }                                                                                             //

    if(ui->spinBox->text().toInt() != 0){ // buy                                                                   //
        if(user->Get_level() >= 2){                                                                                //
            if(user->Get_coin() < ui->spinBox->text().toInt()*3){                                                  //
                //qmessagebox --> "not enough coins to buy this amount of wheat"                                   //
                QMessageBox::critical(this,"NOT ENOUGH COINS","not enough coins to buy this amount of wheat");   //
            }                                                                                                      //
            else{                                                                                                  //
                if(silo->Get_total_storage() - silo->Get_used_storage() < ui->spinBox->text().toInt()){            //
                    //qmessagebox --> "not enough space in silo"                                                   //
                    QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in silo");                     //
                }                                                                                                  //
                else{                                                                                              //
                    silo->Add(1, ui->spinBox->text().toInt());                                                     // buy
                    user->Set_coin(user->Get_coin() - ui->spinBox->text().toInt()*1);                              //
                    user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*2);                  //
                }                                                                                                  //
            }                                                                                                      //
        }                                                                                                          //
        else{                                                                                                      //
            //qmessagebox --> "you must reach level 2 to buy stuff"                                                //
            QMessageBox::critical(this,"LEVEL","you must reach level 2 to buy stuff");                             //
        }                                                                                                          //
    }                                                                                                              //
}

void WheatMarket::Set_values(){
    ui->label->setText(QString::number(silo->Get_used_storage()));
    ui->label_2->setText(QString::number(silo->Get_total_storage() - silo->Get_used_storage()));
}
