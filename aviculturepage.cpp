#include "aviculturepage.h"
#include "ui_aviculturepage.h"
#include <QMessageBox>

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
        QMessageBox::critical(this,"LOCKED","aviculture is locked");
        break;
    case 2:
        //qmessagebox --> "not enough coins for building"
        QMessageBox::critical(this,"COINS","not enough coins for building");
        break;
    case 3:
        //qmessagebox --> "not enough nails for building"
        QMessageBox::critical(this,"NAILS","not enough nails for building");
        break;
    case 4:
        //qmessageboc --> "timer set for building"
        QMessageBox::information(this,"START","timer set for building");
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
    // 6 == timer set for upgrade
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
    }
}

