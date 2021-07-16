#include "agholpage.h"
#include "ui_agholpage.h"
#include <QMessageBox>
AgholPage::AgholPage( Aghol* _aghol, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AgholPage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
    setWindowTitle("Aghol");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

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
    // return values :
    // 1 == already built
    // 2 == locked
    // 3 == not enough coins
    // 4 == not enough nails
    // 5 == not enough shovels
    // 6 == timer set for building
    switch (aghol->Build()){
    case 1:
        //qmessagebox --> "aghol is already built"
        QMessageBox::critical(this,"BUILT","aghol is already built");
        break;
    case 2:
        //qmessagebox --> "aghol is still locked"
        QMessageBox::critical(this,"LEVEL","you cannot build Aghol until you reach level 6");
        break;
    case 3:
        //qmessagebox --> "not enough coins for building aghol"
        QMessageBox::critical(this,"COIN","Not enough coins for building Aghol \n50 coins are needed");
        break;
    case 4:
        //qmessagebox --> "not enough nails for building aghol"
        QMessageBox::critical(this,"NAIL","Not enough nails for building Aghol \n4 nails are needed");
        break;
    case 5:
        //qmessagebox --> "not enough shovels for building aghol"
        QMessageBox::critical(this,"SHOVEL","Not enough shovels for building Aghol \n2 shovels are needed");
        break;
    case 6:
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
        QMessageBox::critical(this,"COIN","Not enough coins for upgrading \n50 coins are needed");
        break;
    case 5:
        //qmessagebox --> "not enough nails for upgrading"
        QMessageBox::critical(this,"NAIL","Not enough nails for upgrading \n1 nail is needed");
        break;
    case 6:
        //qmessagebox --> "not enough shovels for upgrading"
        QMessageBox::critical(this,"SHOVEL","Not enough shovels for upgrading \n3 shovels are needed");
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
        QMessageBox::critical(this,"COIN","Not enough coins for shaving \n1 coin is needed for each sheep");
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

    if(aghol->Get_building_status() == 0){
        ui->label_3->setText("Locked");
    }
    if((aghol->Get_building_status() == 1)&&(aghol->Get_building_timer() == 0)){
        ui->label_3->setText("Not built");
    }
    else if((aghol->Get_building_status() == 1)&&(aghol->Get_building_timer() > 0)){
        ui->label_3->setText("Building... " + QString::number(aghol->Get_building_timer()));
    }
    else if(aghol->Get_upgrade_timer() > 0){
        ui->label_3->setText("Upgrading..." + QString::number(aghol->Get_upgrade_timer()));
    }
    else if((aghol->Get_feeding_status() == 0)&&(aghol->Get_upgrade_timer() == 0)&&(aghol->Get_used_storage() > 0)){
        ui->label_3->setText("Ready to feed");
    }
    else if((aghol->Get_feeding_status() == 0)){
        ui->label_3->setText("Empty");
    }
    else if((aghol->Get_feeding_status() == 1)&&(aghol->Get_upgrade_timer() == 0)){
        ui->label_3->setText("Wool ready in " + QString::number(aghol->Get_feeding_timer()));
    }
    else if((aghol->Get_feeding_status() == 2)&&(aghol->Get_upgrade_timer() == 0)){
        ui->label_3->setText("Wool is ready");
    }
}

