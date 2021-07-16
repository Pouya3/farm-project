#include "alfalfamarket.h"
#include "ui_alfalfamarket.h"
#include <QMessageBox>

AlfalfaMarket::AlfalfaMarket(User* _user, Store* _store, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlfalfaMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);
    setWindowTitle("Alfalfa market");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    user = _user;
    store = _store;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

AlfalfaMarket::~AlfalfaMarket()
{
    delete ui;
}

void AlfalfaMarket::on_pushButton_clicked()
{
    if(user->Get_level() < 3){
        //qmessagebox --> "you cannot buy or sell alfalfa until level 3"
        QMessageBox::critical(this,"LEVEL LIMIT","you cannot buy or sell alfalfa until level 3");
    }
    else{
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

        if(ui->spinBox->text().toInt() != 0){                                                     //
            if(store->Get_object(3) < ui->spinBox->text().toInt()){                               //
                //qmessagbox --> "not enough alfalfa to sell"                                     //
                QMessageBox::critical(this,"0 NOT ENOUGH ALFLFA","not enough alfalfa to sell");   //
            }                                                                                     //
            else{                                                                                 //
                store->Delete(3, ui->spinBox->text().toInt());                                    //
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*4);                 //
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*6);   //
                                                                                                  //
                if(ui->spinBox->text().toInt() == 1){//                                           // sell
                    //qmessagebox --> "alfalfa is sold successfully"                              //
                    QMessageBox::information(this,"SUCCESSFUL TRADE", "1 alfalfa is sold");       //
                }                                                                                 //
                else{                                                                             //
                    //qmessagebox --> "alfalfa is sold successfully"                              //
                    QMessageBox::information(this,"SUCCESSFUL TRADE",                             //
                    QString::number(ui->spinBox->text().toInt()) + " alfalfas are sold");         //
                }                                                                                 //
            }                                                                                     //
        }                                                                                         //

        if(ui->spinBox_2->text().toInt() != 0){ // buy                                                              //
            if(user->Get_coin() < ui->spinBox_2->text().toInt()*6){                                                 //
                //qmessagebox --> "not enough coins to buy this amount of alfalfa"                                  //
                QMessageBox::critical(this,"NOT ENOUGH COINS","not enough coins to buy this amount of alfalfa");    //
            }                                                                                                       //
            else                                                                                                    //
            {                                                                                                       //
                if(store->Get_total_storage() - store->Get_used_storage() < ui->spinBox_2->text().toInt()){         // buy
                    //qmessagebox --> "not enough space in stor"                                                    //
                    QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in stor");                      //
                }                                                                                                   //
                else{                                                                                               //
                    store->Add(3, ui->spinBox_2->text().toInt());                                                   //
                    user->Set_coin(user->Get_coin() - ui->spinBox_2->text().toInt()*6);                             //
                    user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*2);                 //
                                                                                                                    //
                    if(ui->spinBox_2->text().toInt() == 1){//                                                       //
                        //qmessagebox --> "alfalfa is bought successfully"                                          //
                        QMessageBox::information(this,"SUCCESSFUL TRADE", "1 alfalfa is bought");                   //
                    }                                                                                               //
                    else{                                                                                           //
                        //qmessagebox --> "alfalfa is bought successfully"                                          //
                        QMessageBox::information(this,"SUCCESSFUL TRADE",                                           //
                        QString::number(ui->spinBox_2->text().toInt()) + " alfalfas are bought");                   //
                    }                                                                                               //
                }                                                                                                   //
            }                                                                                                       //
        }                                                                                                           //
    }
}

void AlfalfaMarket::Set_values(){
    ui->label->setText(QString::number(store->Get_object(3)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}
