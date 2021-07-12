#include "livestockpage.h"
#include "ui_livestockpage.h"

LivestockPage::LivestockPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LivestockPage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);

    ui->label->setText(QString::number(livestock->Get_level()));
    ui->label_2->setText(QString::number(livestock->Get_used_storage()) + "/" + QString::number(livestock->Get_total_storage()));
    ui->label_3->setText(QString::number(livestock->Get_feeding_timer()));
}

LivestockPage::~LivestockPage()
{
    delete ui;
}

void LivestockPage::on_pushButton_clicked()
{
    switch (livestock->Build()){
    case 1:
        //qmessagebox --> "livestock is still locked"
        break;
    case 2:
        //qmessagebox --> "not enough coins for building livestock"
        break;
    case 3:
        //qmessagebox --> "not enough nails for building livestock"
        break;
    case 4:
        //qmessagebox --> "not enough shovels for building livestock"
        break;
    case 5:
        //qmessagebox --> "timer set for building"
        // set buildning timer
        break;
    }
}


void LivestockPage::on_pushButton_2_clicked()
{
    switch(livestock->Upgrade()){
    case 1:
        //qmessagebox --> "you cannot upgrade livestock until user reaches level 3"
        break;
    case 2:
        //qmessagebox --> "not enough coins for upgrading"
        break;
    case 3:
        //qmessagebox --> "not enough nails for upgrading"
        break;
    case 4:
        //qmessagebox --> "timer set for upgrading"
        //set upgrading timer;
        break;
    }
}


void LivestockPage::on_pushButton_3_clicked()
{
    switch(livestock->Feed()){
    case 1:
        //qmessagbox --> "livestock is empty
        break;
    case 2:
        //qmessagebox --> "you have already fed cows"
        break;
    case 3:
        //qmessagebox --> "to feed cows first collect milks"
        break;
    case 4:
        //qmessagebox --> "not enough alfalfa for feeding"
        break;
    case 5:
        //qmessagbox --> "timer set for milk"
        //set feeding timer;
        break;
    }
}


void LivestockPage::on_pushButton_4_clicked()
{
    switch (livestock->Collect()) {
    case 1:
        //qmessagebox --> "no milk to collect"
        break;
    case 2:
        //qmessagebox --> "not enough space in store for milk"
        break;
    case 3:
        //qmessagebox --> "milks collected successfully"
        break;
    }
}

