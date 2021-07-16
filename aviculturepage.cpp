#include "aviculturepage.h"
#include "ui_aviculturepage.h"
#include <QMessageBox>

AviculturePage::AviculturePage(Aviculture* _aviculture, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AviculturePage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
    setWindowTitle("Aviculture");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    aviculture = _aviculture;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

AviculturePage::~AviculturePage()
{
    delete ui;
}

void AviculturePage::on_pushButton_clicked()
{
    switch(aviculture->Build()){
    case 1:
        //qmessagebox --> "aviculture is already built";
        QMessageBox::critical(this,"BUILT","aviculture is already built");
        break;
    case 2:
        //qmessagebox --> "aviculture is locked";
        QMessageBox::critical(this,"LEVEL","you cannot build aviculture until you reach level 2");
        break;
    case 3:
        //qmessagebox --> "not enough coins for building"
        QMessageBox::critical(this,"COINS","not enough coins for building");
        break;
    case 4:
        //qmessagebox --> "not enough nails for building"
        QMessageBox::critical(this,"NAILS","not enough nails for building");
        break;
    case 5:
        //qmessageboc --> "timer set for building"
        QMessageBox::information(this,"START","timer set for building");
        break;
    }
}


void AviculturePage::on_pushButton_2_clicked()
{
    switch(aviculture->Upgrade()){
    case 1:
        //qmessagebox --> "aviculture is not built yet"
        QMessageBox::critical(this,"NOT BUILT","aviculture is not built yet");
        break;
    case 2:
        //qmessagebox --> "you cannot upgrade aviculture until you reach level 3"
        QMessageBox::critical(this,"LEVEL","you cannot upgrade aviculture until you reach level 3");
        break;
    case 3:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COINS","not enough coins for upgrading");
        break;
    case 4:
        //qmessagebox --> "not enough nails for upgrading"
        QMessageBox::critical(this,"NAILS","not enough nails for upgrading");
        break;
    case 5:
        QMessageBox::critical(this,"UPGEADING","aviculture is already in upgrading situation");
        break;
    case 6:
        //qmessagebox --> "timer set for upgrading"
        QMessageBox::information(this,"START","timer set for upgrading");
        break;
    }
}
void AviculturePage::on_pushButton_3_clicked()
{
    switch(aviculture->Feed()){
    case 1:
        //qmessagebox --> "aviculture is not built yet"
        QMessageBox::critical(this,"NOT BUILT","aviculture is not built yet");
        break;
    case 2:
        //qmessagebox --> "aviculture is empty"
        QMessageBox::critical(this,"EMPTY","aviculture is empty");
        break;
    case 3:
        //qmessagebox --> "you have to wait for timer to finish and collect egg to feed chickens"
        QMessageBox::critical(this,"NOT READY AND NOT COLLECTED PRODUCT","you have to wait for timer to finish and collect egg to feed chickens");
        break;
    case 4:
        QMessageBox::critical(this,"UPGEADING","After Aghol upgraded you can feed them");
        break;
    case 5:
        //qmessagebox --> "not enough wheat for feeding"
        QMessageBox::critical(this,"NOT ENOUGH WHEAT","not enough wheat for feeding");
        break;
    case 6:
        //qmessagebox --> "timer set for eggs"
        QMessageBox::information(this,"START","timer set for eggs");
        break;
    }
}


void AviculturePage::on_pushButton_4_clicked()
{
    switch (aviculture->Collect()) {
    case 1:
        //qmessagebox --> "no egg to collect"
        QMessageBox::critical(this,"NO EGG","no egg to collect");
        break;
    case 2:
        //qmessagebox --> "not enough space in store for eggs"
        QMessageBox::critical(this,"NOT ENOUGH SPACE","not enough space in store for eggs");
        break;
    case 3:
        //qmessagebox --> "eggs collected successfully"
        QMessageBox::information(this,"SUCCESS","eggs collected successfully");
        break;
    case 4:
        //qmessagebox --> "aviculture is not built yet"
        QMessageBox::critical(this,"NOT BUILT","aviculture is not built yet");
        break;
    }
}

void AviculturePage::Set_values(){
    ui->label->setText(QString::number(aviculture->Get_level()));
    ui->label_2->setText(QString::number(aviculture->Get_used_storage()) + "/" + QString::number(aviculture->Get_total_storage()));

    if(aviculture->Get_building_status() == 0){
        ui->label_3->setText("Locked");
    }
    else if((aviculture->Get_building_status() == 1)&&(aviculture->Get_building_timer() == 0)){
        ui->label_3->setText("Not built");
    }
    else if((aviculture->Get_building_status() == 1)&&(aviculture->Get_building_timer() > 0)){
        ui->label_3->setText("Building..." + QString::number(aviculture->Get_building_timer()));
    }
    else if(aviculture->Get_upgrade_timer() > 0){
        ui->label_3->setText("Upgrading" + QString::number(aviculture->Get_upgrade_timer()));
    }
    else if((aviculture->Get_feeding_status() == 0)&&(aviculture->Get_used_storage() > 0)){
        ui->label_3->setText("Ready to feed");
    }
    else if(aviculture->Get_feeding_status() == 1){
        ui->label_3->setText("Eggs ready in " + QString::number(aviculture->Get_feeding_timer()));
    }
    else {
        ui->label_3->setText("Eggs ready");
    }
}
