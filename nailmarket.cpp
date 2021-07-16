#include "nailmarket.h"
#include "ui_nailmarket.h"

NailMarket::NailMarket(User* _user, Store* _store, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NailMarket)
{
    ui->setupUi(this);
    setFixedSize(1000,570);

    user = _user;
    store = _store;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

NailMarket::~NailMarket()
{
    delete ui;
}

void NailMarket::on_pushButton_clicked()
{

    if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
        // qmessagebox --> "number of buying and selling items is 0"
        QMessageBox::critical(this,"0 VALUE","number of buying and selling items is 0");
        return;
    }

    if((ui->spinBox->text().toInt() != 0)&&(ui->spinBox_2->text().toInt() != 0)){
        // qmessagebox --> "you cannot buy and sell at the same time"
        QMessageBox::critical(this,"BUY AND SELL","you cannot buy and sell at the same time");
        return;
    }

    if(ui->spinBox_2->text().toInt() != 0){                                                     //
        if(user->Get_level() >= 2){                                                             //
            if(store->Get_object(2) < ui->spinBox_2->text().toInt()){                           //
                //qmessagbox --> "not enough nails to sell"                                     //
                QMessageBox::critical(this,"NOT ENOUGH NAILS","not enough nails to sell");      //
            }                                                                                   //
            else{                                                                               //
                store->Delete(2, ui->spinBox_2->text().toInt());                                //
                user->Set_coin(user->Get_coin() + ui->spinBox_2->text().toInt()*20);            // sell
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*6); //
                                                                                                //
                if(ui->spinBox_2->text().toInt() == 1){//                                       //
                    //qmessagebox --> "nail is sold successfully"                               //
                    QMessageBox::information(this,"SUCCESSFUL TRADE", "1 nail is sold");        //
                }                                                                               //
                else{                                                                           //
                    //qmessagebox --> "nail is sold successfully"                               //
                    QMessageBox::information(this,"SUCCESSFUL TRADE",                           //
                    QString::number(ui->spinBox_2->text().toInt()) + " nails are sold");        //
                }                                                                               //
            }                                                                                   //
        }                                                                                       //
        else{                                                                                   //
            //qmessagebox --> "you must reach level 2 to sell stuff"                            //
            QMessageBox::critical(this,"LEVEL","you must reach level 2 to sell stuff");         //
        }                                                                                       //
    }                                                                                           //

    if(ui->spinBox->text().toInt() != 0){ // buy                                                                    //
        if(user->Get_level() >= 2){                                                                                 //
            if(user->Get_coin() < ui->spinBox->text().toInt()*30){                                                  //
                //qmessagebox --> "not enough coins to buy this number of nails"                                    //
                QMessageBox::critical(this,"NOT ENOUGH COINS","not enough coins to buy this number of nails");      //
            }                                                                                                       //
            else{                                                                                                   //
                if(store->Get_total_storage() - store->Get_used_storage() < ui->spinBox->text().toInt()){           //
                    //qmessagebox --> "not enough space in store"                                                   //
                    QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in store");                     //
                }                                                                                                   //
                else{                                                                                               // buy
                    store->Add(2, ui->spinBox->text().toInt());                                                     //
                    user->Set_coin(user->Get_coin() - ui->spinBox->text().toInt()*30);                              //
                    user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*2);                   //
                                                                                                                    //
                    if(ui->spinBox->text().toInt() == 1){//                                                         //
                        //qmessagebox --> "nail is bought successfully"                                             //
                        QMessageBox::information(this,"SUCCESSFUL TRADE", "1 nail is bought");                      //
                    }                                                                                               //
                    else{                                                                                           //
                        //qmessagebox --> "nail is bought successfully"                                             //
                        QMessageBox::information(this,"SUCCESSFUL TRADE",                                           //
                        QString::number(ui->spinBox->text().toInt()) + " nails are bought");                        //
                    }                                                                                               //
                }                                                                                                   //
            }                                                                                                       //
        }                                                                                                           //
        else{                                                                                                       //
            //qmessagebox --> "you must reach level 2 to buy stuff"                                                 //
            QMessageBox::critical(this,"LEVEL","you must reach level 2 to buy stuff");                              //
        }                                                                                                           //
    }                                                                                                               //
}

void NailMarket::Set_values(){
    ui->label_2->setText(QString::number(store->Get_object(2)));
    ui->label->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}
