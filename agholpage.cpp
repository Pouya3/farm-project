#include "agholpage.h"
#include "ui_agholpage.h"

AgholPage::AgholPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AgholPage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);

    ui->label->setText(QString::number(aghol->Get_level()));
    ui->label_2->setText(QString::number(aghol->Get_used_storage()) + "/" + QString::number(aghol->Get_total_storage()));
    ui->label_3->setText(QString::number(aghol->Get_feeding_timer()));

}

AgholPage::~AgholPage()
{
    delete ui;
}

void AgholPage::on_pushButton_clicked()
{
    switch (aghol->Build()){
    case 1:
        //qmessagebox --> "aghol is still locked"
        break;
    case 2:
        //qmessagebox --> "not enough coins for building aghol"
        break;
    case 3:
        //qmessagebox --> "not enough nails for building aghol"
        break;
    case 4:
        //qmessagebox --> "not enough shovels for building aghol"
        break;
    case 5:
        //qmessagebox --> "timer set for building"
        // set buildning timer
        aghol->Set_building_timer(10);
        break;
    }
}


void AgholPage::on_pushButton_2_clicked()
{
    switch (aghol->Upgrade()){
    case 1:
        //qmessagebox --> "aghol is not built yet"
        break;
    case 2:
        //qmessagebox --> "you cannot upgrade until feeding timer finishes and wools get collected"
        break;
    case 3:
        //qmessagebox --> "you cannot upgrade aghol until user reaches to level 7"
        break;
    case 4:
        //qmessagebox --> "not enough coins for upgrading"
        break;
    case 5:
        //qmessagebox --> "not enough nails for upgrading
        break;
    case 6:
        //qmessagebox --> "not enough shovels for upgrading"
        break;
    case 7:
        //qmessagebox --> "timer set for upgrading"
        // set upgrading timer"
        aghol->Set_upgrade_timer(9);
        break;
    }
}


void AgholPage::on_pushButton_3_clicked()
{
    switch(aghol->Feed()){
    case 1:
        //qmessagebox --> "aghol is not built yet"
        break;
    case 2:
        //qmessagebox --> "aghol is empty"
        break;
    case 3:
        //qmessagebox --> "after timer finished and sheep are shaved youn can feed them"
        break;
    case 4:
        //qmessagebox --> "not enough alfalfa for feeding"
        break;
    case 5:
        //qmessagebox --> "timer set for product"
        // set feeding timer
        aghol->Set_feeding_timer(10);
        break;
    }
}


void AgholPage::on_pushButton_4_clicked()
{
    switch(aghol->Collect()){
    case 1:
        //qmessagebox --> "aghol is not built yet"
        break;
    case 2:
        //qmessagebox --> "no wool to shave"
        break;
    case 3:
        //qmessagebox --> "not enough coins for shaving"
        break;
    case 4:
        //qmessagebox --> "not enough space in store for wools"
        break;
    case 5:
        //qmessagebox --> "wool shaved successfully"
        break;
    }
}

