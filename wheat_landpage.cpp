#include "wheat_landpage.h"
#include "spacepage_2.h"
#include "ui_wheat_landpage.h"

Wheat_landPage::Wheat_landPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wheat_landPage)
{
    ui->setupUi(this);
    this->setFixedSize(1250,550);

    ui->label->setText(QString::number(wheat_land->Get_level()));
    ui->label_2->setText(QString::number(wheat_land->Get_cultivated_area()) + "/" + QString::number(wheat_land->Get_total_area()));
    if((wheat_land->Get_upgrade_timer() == 0)&&(wheat_land->Get_cultivation_status() == 0)){
        ui->label_3->setText("--");
    }
    else if(wheat_land->Get_upgrade_timer() > 0){
        ui->label_3->setText(QString::number(wheat_land->Get_upgrade_timer()));
    }
    else if((wheat_land->Get_cultivation_status() == 1)&&(wheat_land->Get_ripening_timer() > 0)){
        ui->label_3->setText(QString::number(wheat_land->Get_ripening_timer()));
    }
    else{
        ui->label_3->setText("0");
    }
}

Wheat_landPage::~Wheat_landPage()
{
    delete ui;
}

void Wheat_landPage::on_pushButton_clicked()
{
    if(wheat_land->Get_cultivation_status() != 0){
        //qmessagebox --> "you have to wait for wheats to ripen and harvest them to cultivate"
        QMessageBox::critical(this,"WAIT","You have to wait for wheats to ripen and harvest them to cultivate");
    }
    else{
        SpacePage_2* s=new SpacePage_2;
        s->show();
        this->close();
    }
}


void Wheat_landPage::on_pushButton_3_clicked()
{
    // return values :
    // 1 == you have to wait unlit wheats ripen and collect them to upgrade
    // 2 == not enough shovels
    // 3 == not enough coins
    // 4 == limit for upgrade duo to user's level
    // 5 == timer set for upgrade

    switch(wheat_land->Upgrade()){
    case 1:
        //qmessagebox --> "you have to wait for wheats to ripen and harvest them to upgrade"
        QMessageBox::critical(this,"WAIT","You have to wait for wheats to ripen and harvest them to upgrade");
        break;
    case 2:
        //qmessagebox --> "not enough shovels for upgrading"
        QMessageBox::critical(this,"SHOVEL","Not enough shovels for upgrading");
        break;
    case 3:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COIN","Not enough coins for upgrading");
        break;
    case 4:
        //qmessagebox --> "you cannot upgrade wheat land until you reach level 2"
        QMessageBox::critical(this,"LEVEL","You cannot upgrade wheat land until you reach level 2");
        break;
    case 7:
        QMessageBox::critical(this,"UPGEADING","Wheat land is already in upgrading situation");
        break;
    case 6:
        //qmessagebox --> "timer set for upgrading"
        QMessageBox::information(this,"START","Timer set for upgrading");
        break;
    }
}


void Wheat_landPage::on_pushButton_2_clicked()
{
    switch (wheat_land->Harvest()) {
    case 1:
        //qmessagebox --> "nothing to harvest"
        QMessageBox::critical(this,"EMPTY","Nothing to harvest");
        break;
    case 2:
        //qmessagebox --> "not enough space in silo"
        QMessageBox::critical(this,"SPACE","Not enough space in silo");
        break;
    case 3:
        //messagebox --> "harvested successfully"
        QMessageBox::information(this,"HARVESTED","Harvested successfully");
        break;
    }
}

