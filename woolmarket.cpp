#include "woolmarket.h"
#include "ui_woolmarket.h"

WoolMarket::WoolMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WoolMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);

    ui->label->setText(QString::number(store->Get_object(6)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}

WoolMarket::~WoolMarket()
{
    delete ui;
}

void WoolMarket::on_pushButton_clicked()
{
    if(user->Get_level() < 6){
        //qmessagebox --> "you must reach level 6 to buy or sell wool"
    }
    else{
        if(ui->spinBox->text().toInt() != 0){
            //qmessagebox --> "number of selling items is 0"
        }
        else{
            if(store->Get_object(6) < ui->spinBox->text().toUInt()){
                //qmessagebox --> "not enough milks to sell"
            }
            else{
                store->Delete(6, ui->spinBox->text().toInt());
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*23);
            }
        }
    }
}

