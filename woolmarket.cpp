#include "woolmarket.h"
#include "ui_woolmarket.h"

WoolMarket::WoolMarket(User* _user, Store* _store, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WoolMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);

    user = _user;
    store = _store;

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
        //qmessagebox --> "you must reach level 6 to sell wool"
        QMessageBox::critical(this,"LEVEL","You must reach level 6 to sell wool");
    }
    else{
        if(ui->spinBox->text().toInt() != 0){
            //qmessagebox --> "number of selling items is 0"
            QMessageBox::critical(this,"0 VALUE","Number of selling items is 0");
        }
        else{
            if(store->Get_object(6) < ui->spinBox->text().toInt()){
                //qmessagebox --> "not enough wool to sell"
                QMessageBox::critical(this,"NOT ENOUGH WOOL","Not enough wool to sell");
            }
            else{
                store->Delete(6, ui->spinBox->text().toInt());
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*23);
                user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*6);
            }
        }
    }
}

