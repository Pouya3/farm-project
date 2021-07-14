#include "agholpage.h"
#include "ui_agholpage.h"
#include <QMessageBox>
AgholPage::AgholPage( Aghol* _aghol, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AgholPage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);

    aghol = _aghol;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

AgholPage::~AgholPage()
{
    delete ui;
}

void AgholPage::on_pushButton_clicked()
{

    switch (aghol->Build()){
    case 1:{
        //qmessagebox --> "aghol is still locked"
        QMessageBox::critical(this,"LOCK","Aghol is still locked");
    }
        break;
    case 2:
        //qmessagebox --> "not enough coins for building aghol"
        QMessageBox::critical(this,"COIN","Not enough coins for building Aghol");
        break;
    case 3:
        //qmessagebox --> "not enough nails for building aghol"
        QMessageBox::critical(this,"NAIL","Not enough nails for building Aghol");
        break;
    case 4:
        //qmessagebox --> "not enough shovels for building aghol"
        QMessageBox::critical(this,"SHOVEL","Not enough shovels for building Aghol");
        break;
    case 5:
        //qmessagebox --> "timer set for building"
        QMessageBox::information(this,"START","Timer set for building");
        break;
    }
}


void AgholPage::on_pushButton_2_clicked()
{
    switch (aghol->Upgrade()){
    case 1:
        //qmessagebox --> "aghol is not built yet"
        QMessageBox::critical(this,"NOT BUILT","Aghol is not built yet");
        break;
    case 2:
        //qmessagebox --> "you cannot upgrade until feeding timer finishes and wools get collected"
        QMessageBox::critical(this,"FEEDING","You cannot upgrade until feeding timer finishes and wools get collected");
        break;
    case 3:
        //qmessagebox --> "you cannot upgrade aghol until user reaches to level 7"
        QMessageBox::critical(this,"LEVEL","You cannot upgrade aghol until user reaches to level 7");
        break;
    case 4:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COIN","Not enough coins for upgrading");
        break;
    case 5:
        //qmessagebox --> "not enough nails for upgrading"
        QMessageBox::critical(this,"NAIL","Not enough nails for upgrading");
        break;
    case 6:
        //qmessagebox --> "not enough shovels for upgrading"
        QMessageBox::critical(this,"SHOVEL","Not enough shovels for upgrading");
        break;
    case 7:
        QMessageBox::critical(this,"UPGEADING","Aghol is already in upgrading situation");
        break;
    case 8:
        //qmessagebox --> "timer set for upgrading"
        QMessageBox::information(this,"START","Timer set for upgrading");
        break;
    }
}


void AgholPage::on_pushButton_3_clicked()
{
    switch(aghol->Feed()){
    case 1:
        //qmessagebox --> "aghol is not built yet"
        QMessageBox::critical(this,"BUILT","Aghol is not built yet");
        break;
    case 2:
        //qmessagebox --> "aghol is empty"
        QMessageBox::critical(this,"EMPTY","Aghol is empty");
        break;
    case 3:
        //qmessagebox --> "after timer finished and sheep are shaved youn can feed them"
        QMessageBox::critical(this,"TIMER","After timer finished and sheep are shaved you can feed them");
        break;
    case 4:       
        QMessageBox::critical(this,"UPGEADING","After Aghol upgraded you can feed them");
        break;
    case 5:
        //qmessagebox --> "not enough alfalfa for feeding"
        QMessageBox::critical(this,"ALFALFA","Not enough alfalfa for feeding");
        break;
    case 6:
        //qmessagebox --> "timer set for product"
        QMessageBox::information(this,"START","Timer set for product");
        break;
    }
}


void AgholPage::on_pushButton_4_clicked()
{
    switch(aghol->Collect()){
    case 1:
        //qmessagebox --> "aghol is not built yet"
        QMessageBox::critical(this,"BUILT","Aghol is not built yet");
        break;
    case 2:
        //qmessagebox --> "no wool to shave"
        QMessageBox::critical(this,"WOOL","No wool to shave");
        break;
    case 3:
        //qmessagebox --> "not enough coins for shaving"
        QMessageBox::critical(this,"COIN","Not enough coins for shaving");
        break;
    case 4:
        //qmessagebox --> "not enough space in store for wools"
        QMessageBox::critical(this,"SPACE","Not enough space in store for wools");
        break;
    case 5:
        //qmessagebox --> "wool shaved successfully"
        QMessageBox::information(this,"SHAVED","Wool shaved successfully");
        break;
    }
}

void AgholPage::Set_values(){
    ui->label->setText(QString::number(aghol->Get_level()));
    ui->label_2->setText(QString::number(aghol->Get_used_storage()) + "/" + QString::number(aghol->Get_total_storage()));
    ui->label_3->setText(QString::number(aghol->Get_feeding_timer()));
}

