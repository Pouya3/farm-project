#include "eggmarket.h"
#include "ui_eggmarket.h"

eggMarket::eggMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eggMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);

    ui->label->setText(QString::number(store->Get_object(4)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}

eggMarket::~eggMarket()
{
    delete ui;
}

void eggMarket::on_pushButton_clicked()
{
    if(user->Get_level() < 2){
        //qmessagebox --> "you must reach level 2 to buy or sell egg"
        QMessageBox::critical(this,"LEVEL","you must reach level 2 to buy or sell egg");
    }
    else{
        if(ui->spinBox->text().toInt() != 0){
            //qmessagebox --> "number of selling items is 0"
            QMessageBox::critical(this,"0 VALUE","number of selling items is 0");
        }
        else{
            if(store->Get_object(4) < ui->spinBox->text().toUInt()){
                //qmessagebox --> "not enough eggs to sell"
                QMessageBox::critical(this,"NOT ENOUGH EGGS","not enough eggs to sell");
            }
            else{
                store->Delete(4, ui->spinBox->text().toInt());
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*8);
            }
        }
    }
}

