#include "alfalfa_landpage.h"
#include "ui_alfalfa_landpage.h"
#include "spacepage.h"

Alfalfa_landPage::Alfalfa_landPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alfalfa_landPage)
{
    ui->setupUi(this);
    this->setFixedSize(1200,530);

    ui->label->setText(QString::number(alfalfa_land->Get_level()));
    ui->label_2->setText(QString::number(alfalfa_land->Get_cultivated_area()) + "/" + QString::number(alfalfa_land->Get_total_area()));
    if(alfalfa_land->Get_upgrade_timer() > 0){
        ui->label_3->setText(QString::number(alfalfa_land->Get_upgrade_timer()));
    }
    else if((alfalfa_land->Get_cultivation_status() == 0)&&(alfalfa_land->Get_plowing_timer() == 0)){
        ui->label_3->setText("--");
    }
    else if((alfalfa_land->Get_cultivation_status() == 0)&&(alfalfa_land->Get_plowing_timer() > 0)){
        ui->label_3->setText(QString::number(alfalfa_land->Get_plowing_timer()));
    }
    else if(alfalfa_land->Get_cultivation_status() == 1){
        ui->label_3->setText("0");
    }
    else if((alfalfa_land->Get_cultivation_status() == 2)&&(alfalfa_land->Get_ripening_timer() > 0)){
        ui->label_3->setText(QString::number(alfalfa_land->Get_ripening_timer()));
    }
    else if((alfalfa_land->Get_cultivation_status() == 2)&&(alfalfa_land->Get_ripening_timer() == 0)){
        ui->label_3->setText("0");
    }
}

Alfalfa_landPage::~Alfalfa_landPage()
{
    delete ui;
}

void Alfalfa_landPage::on_pushButton_clicked()
{

    switch(alfalfa_land->Build()){
    case 1:
        //qmessagebox --> "you cannot build alfalfa land until youreach level 3"
        break;
    case 2:
        //qmessagebox --> "not enough coins to build alfalfa land"
        break;
    case 3:
        //qmessagebox --> "not enough shovels to build alfalfa land"
        break;
    case 4:
        //qmessagebox --> "not enough nails to build alfalfa land"
        break;
    case 5:
        //qmessagebox --> "timer set for building alfalfa land"
        break;
    }
}


void Alfalfa_landPage::on_pushButton_2_clicked()
{
    switch (alfalfa_land->Upgrade()) {
    case 1:
        //qmessagebox --> "alfalfa land is not built yet"
        break;
    case 2:
        //qmessagebox --> "you cannot upgrade until alfalfs ripen and get harvested"
        break;
    case 3:
        //qmessagebox --> "not enough shovels for upgrading"
        break;
    case 4:
        //qmessagebox --> "not enough coins for upgrading"
        break;
    case 5:
        //qmessagebox --> "you cannot upgrade alfalfa land until you reach level 4"
        break;

    }
}


void Alfalfa_landPage::on_pushButton_3_clicked()
{
    switch (alfalfa_land->Plow()) {
    case 1:
        //qmessagebox --> "you have to wait until alfalfa ripens and gets collected"
        break;
    case 2:
        //qmessagebox --> "field is cultivated. you cannot plow"
        break;
    case 3:
        //qmessagebox --> "not enough coins for plowing"
        break;
    case 4:
        //qmessagebox --> "timer set for plowing"
        break;
    case 5:
        //qmessagebox --> "alfalfa land is not built yet"
        break;
    }
}

void Alfalfa_landPage::on_pushButton_4_clicked()
{
    if(alfalfa_land->Get_building_status() != 2){
        //qmessagebox --> "alfalfa land is not built yet
    }
    else if(alfalfa_land->Get_cultivation_status() == 1){
        //qmessagbox --> "alfalfa land is already plowed"
    }
    else if ((alfalfa_land->Get_cultivation_status() == 2)||(alfalfa_land->Get_cultivation_status() == 3)){
        //qmessagebox --> "alfalfa land is cultivated"
    }
    else{
        SpacePage* s=new SpacePage;
        s->show();
        this->close();
    }
}

void Alfalfa_landPage::on_pushButton_5_clicked()
{
    switch (alfalfa_land->Harvest()) {
    case 1:
        //qmessagebox --> "no alfalfa to harvest"
        break;
    case 2:
        //qmessagebox --> "not enough space in store"
        break;
    case 3:
        //qmessagebox --> "harvested successfully"
        break;
    }
}

