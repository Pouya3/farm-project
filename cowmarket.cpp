#include "cowmarket.h"
#include "ui_cowmarket.h"

CowMarket::CowMarket(User* _user, Livestock* _livestock, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CowMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,570);
    setWindowTitle("Cow market");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    user = _user;
    livestock = _livestock;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

CowMarket::~CowMarket()
{
    delete ui;
}

void CowMarket::on_pushButton_clicked() // buy -> 1             sell -> 2
{
    if(livestock->Get_building_status() != 2){
        //qmessagebox --> "you must build livestock to buy or sell cow"
        QMessageBox::critical(this,"LIVESTOCK NOT BUILT","you must build livestock to buy or sell cow");
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
            if(livestock->Get_used_storage() < ui->spinBox_2->text().toInt()){                                      //
                //qmessagebox --> "not enough cows to sell"                                                         //
                QMessageBox::critical(this,"NOT ENOUGH COWS","not enough cows to sell");                            //
            }                                                                                                       //
            else{                                                                                                   // sell
                livestock->Delete(1, ui->spinBox_2->text().toInt());                                                //
                user->Set_coin(user->Get_coin() + ui->spinBox_2->text().toInt()*50);                                //
                user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*6);                       //
                                                                                                                    //
                if(ui->spinBox_2->text().toInt() == 1){//                                                           //
                    //qmessagebox --> "cow is sold successfully"                                                    //
                    QMessageBox::information(this,"SUCCESSFUL TRADE", "1 cow is sold");                             //
                }                                                                                                   //
                else{                                                                                               //
                    //qmessagebox --> "cow is sold successfully"                                                    //
                    QMessageBox::information(this,"SUCCESSFUL TRADE",                                               //
                    QString::number(ui->spinBox_2->text().toInt()) + " cows are sold");                             //
                }                                                                                                   //
            }                                                                                                       //
        }

        if(ui->spinBox->text().toInt() != 0){                                                                       //
            if(user->Get_coin() < ui->spinBox->text().toInt()*70){                                                  //
                //qmessagebox --> "not enough coins to buy this number of cows"                                     //
                QMessageBox::critical(this,"NOT ENOUGH COINS","not enough coins to buy this number of cows");       //
            }                                                                                                       //
            else{                                                                                                   //
                if(livestock->Get_total_storage() - livestock->Get_used_storage() < ui->spinBox->text().toInt()){   //
                    //qmessagebox --> "not enough space in livestock"                                               //
                    QMessageBox::critical(this,"NOT ENOUGH SAPCE","not enough space in livestock");                 // buy
                }                                                                                                   //
                else{                                                                                               //
                    livestock->Add(1, ui->spinBox->text().toInt());                                                 //
                    user->Set_coin(user->Get_coin() - ui->spinBox->text().toInt()*70);                              //
                    user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*2);                   //
                                                                                                                    //
                    if(ui->spinBox->text().toInt() == 1){//                                                         //
                        //qmessagebox --> "cow is bought successfully"                                              //
                        QMessageBox::information(this,"SUCCESSFUL TRADE", "1 cow is bought");                       //
                    }                                                                                               //
                    else{                                                                                           //
                        //qmessagebox --> "cow is bought successfully"                                              //
                        QMessageBox::information(this,"SUCCESSFUL TRADE",                                           //
                        QString::number(ui->spinBox_2->text().toInt()) + " cows are bought");                       //
                    }                                                                                               //
                }                                                                                                   //
            }                                                                                                       //
        }                                                                                                           //
    }
}

void CowMarket::Set_values(){
    ui->label->setText(QString::number(livestock->Get_used_storage()));
    ui->label_2->setText(QString::number(livestock->Get_total_storage()- livestock->Get_used_storage()));
}
