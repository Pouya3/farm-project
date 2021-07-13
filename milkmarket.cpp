#include "milkmarket.h"
#include "ui_milkmarket.h"

MilkMarket::MilkMarket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MilkMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);

    ui->label->setText(QString::number(store->Get_object(5)));
    ui->label->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}

MilkMarket::~MilkMarket()
{
    delete ui;
}

void MilkMarket::on_pushButton_clicked()
{
    if(user->Get_level() < 4){
        //qmessagebox --> "you must reach level 4 to sell milk"
        QMessageBox::critical(this,"LEVEL","you must reach level 4 to sell milk");
    }
    else{
        if(ui->spinBox->text().toInt() != 0){
            //qmessagebox --> "number of selling items is 0"
            QMessageBox::critical(this,"0 VALUE","number of selling items is 0");
        }
        else{
            if(store->Get_object(5) < ui->spinBox->text().toUInt()){
                //qmessagebox --> "not enough milks to sell"
                QMessageBox::critical(this,"NOT ENOUGH MILKS","not enough milks to sell");
            }
            else{
                store->Delete(5, ui->spinBox->text().toInt());
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*12);
                user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*6);
            }
        }
    }
}

