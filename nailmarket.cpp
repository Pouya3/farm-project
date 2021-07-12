#include "nailmarket.h"
#include "ui_nailmarket.h"

NailMarket::NailMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NailMarket)
{
    ui->setupUi(this);
    setFixedSize(1000,570);

    ui->label_2->setText(QString::number(store->Get_object(2)));
    ui->label->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}

NailMarket::~NailMarket()
{
    delete ui;
}

void NailMarket::on_pushButton_clicked()
{

    if((ui->spinBox->text().toInt() == 0)&&(ui->spinBox_2->text().toInt() == 0)){
        // qmessagebox --> "number of buying and selling items is 0"
        return;
    }

    if(ui->spinBox->text().toInt() != 0){                                            //
        if(store->Get_object(2) < ui->spinBox->text().toInt()){                      //
            //qmessagbox --> "not enough nails to sell"                              //
        }                                                                            // sell
        else{                                                                        //
            store->Delete(2, ui->spinBox->text().toInt());                           //
            user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*20);       //
        }                                                                            //
    }                                                                                //

    if(ui->spinBox_2->text().toInt() != 0){ // buy                                                   //
        if(store->Get_total_storage() - store->Get_used_storage() < ui->spinBox_2->text().toInt()){  //
            //qmessagebox --> "not enough nails"                                                     //
        }                                                                                            //
        else{                                                                                        //
            store->Add(2, ui->spinBox_2->text().toInt());                                            // buy
            user->Set_coin(user->Get_coin() - ui->spinBox_2->text().toInt()*30);                     //
            user->Set_experience(user->Get_experience() + ui->spinBox_2->text().toInt()*4);          //
        }                                                                                            //
    }                                                                                                //

}

