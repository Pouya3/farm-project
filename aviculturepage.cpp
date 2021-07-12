#include "aviculturepage.h"
#include "ui_aviculturepage.h"

AviculturePage::AviculturePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AviculturePage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);

    ui->label->setText(QString::number(aviculture->Get_level()));
    ui->label_2->setText(QString::number(aviculture->Get_used_storage()) + "/" + QString::number(aviculture->Get_total_storage()));
    ui->label_3->setText(QString::number(aviculture->Get_feeding_timer()));
}

AviculturePage::~AviculturePage()
{
    delete ui;
}

void AviculturePage::on_pushButton_clicked()
{
    switch(aviculture->Build()){
    case 1:
        //qmessagebox --> "aviculture is locked";
        break;
    case 2:
        //qmessagebox --> "not enough coins for building"
        break;
    case 3:
        //qmessagebox --> "not enough nails for building"
        break;
    case 4:
        //qmessageboc --> "timer set for building"
        //set building timer
        aviculture->Set_building_timer(3);
        break;
    }
}


void AviculturePage::on_pushButton_2_clicked()
{
    // return values :
    // 1 == is not built yet
    // 2 == limit for building duo to user's level
    // 3 == not enough coins
    // 4 == not enough nails
    // 5 == timer set for upgrade
    switch(aviculture->Upgrade()){
    case 1:
        //qmessagebox --> "aviculture is not built yet"
        break;
    case 2:
        //qmessagebox --> "you cannot upgrade aviculture until user reaches level 3"
        break;
    case 3:
        //qmessagebox --> "not enough coins for upgrading"
        break;
    case 4:
        //qmessagebox --> "not enough nails for upgrading"
        break;
    case 5:
        //qmessagebox --> "timer set for upgrading"
        //set upgrading timer;
        aviculture->Set_upgrade_timer(3);
        break;
    }
}
void AviculturePage::on_pushButton_3_clicked()
{
    switch(aviculture->Feed()){
    case 1:
        //qmessagebox --> "aviculture is empty"
        break;
    case 2:
        //qmessagebox --> "you have to wait for timer to finish and collect egg to feed chickens"
        break;
    case 3:
        //qmessagebox --> "not enough wheat for feeding"
        break;
    case 4:
        //qmessagebox --> "timer set for eggs"
        // set feeding timer;
        aviculture->Set_feeding_timer(2);
        break;
    }
}


void AviculturePage::on_pushButton_4_clicked()
{
    switch (aviculture->Collect()) {
    case 1:
        //qmessagebox --> "no egg to collect"
        break;
    case 2:
        //qmessagebox --> "not enough space in store for eggs"
        break;
    case 3:
        //qmessagebox --> "eggs collected successfully"
        break;
    }
}

