#include "chickenmarket.h"
#include "ui_chickenmarket.h"

ChickenMarket::ChickenMarket(User* _user, Aviculture* _aviculture, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChickenMarket)
{
    ui->setupUi(this);
    setFixedSize(1000,570);

    user = _user;
    aviculture = _aviculture;

    ui->label_2->setText(QString::number(aviculture->Get_used_storage()));
    ui->label->setText(QString::number(aviculture->Get_total_storage() - aviculture->Get_used_storage()));
}

ChickenMarket::~ChickenMarket()
{
    delete ui;
}

void ChickenMarket::on_pushButton_clicked()
{
    if(aviculture->Get_building_status() != 2){
        //messagebox --> "to buy chickens you must build aviculture first"
        QMessageBox::critical(this,"AVICULTURE NOT BUILT","to buy chickens you must build aviculture first");
    }
    else{
        if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() != 0)){
           //qmessagebox --> "number of buying and selling items is 0"
            QMessageBox::critical(this,"0 VALUE","number of buying and selling items is 0");
            return;
        }

        if(ui->spinBox->text().toInt() != 0){                                                                //
            if(user->Get_level() >= 3){                                                                      //
                if(aviculture->Get_used_storage() < ui->spinBox->text().toInt()){                            //
                    //qmessagebox --> "not enough chickens to sell"                                          //
                    QMessageBox::critical(this,"NOT ENOUGH CHICKENS","not enough chickens to sell");         //
                }                                                                                            //
                else{                                                                                        //
                    aviculture->Delete(1, ui->spinBox->text().toInt());                                      //
                    user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*15);                       // sell
                    user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*6);          //
                }                                                                                            //
            }                                                                                                //
            else{                                                                                            //
                //qmessagebox --> "you cannot sell anything until you reach level 3"                         //
                QMessageBox::critical(this,"LEVEL","you cannot sell anything until you reach level 3");      //
            }                                                                                                //
        }                                                                                                    //

        if(ui->spinBox_2->text().toInt() != 0){                                                                     //
            if(aviculture->Get_total_storage() - aviculture->Get_used_storage() < ui->spinBox_2->text().toInt()){   //
                //qmessagebox --> "not enough space in aviculture"                                                  //
                QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in aviculture");                    //
            }                                                                                                       //
            else{                                                                                                   // buy
                aviculture->Add(1, ui->spinBox_2->text().toInt());                                                  //
                user->Set_coin(user->Get_coin() - ui->spinBox_2->text().toInt()*20);                                //
                user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*2);                     //
            }                                                                                                       //
        }
    }
}

