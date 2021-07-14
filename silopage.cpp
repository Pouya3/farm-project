#include "silopage.h"
#include "ui_silopage.h"

SiloPage::SiloPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SiloPage)
{
    ui->setupUi(this);
    this->setFixedSize(1000,660);

    ui->label->setText(QString::number(silo->Get_level()));
    ui->label_2->setText(QString::number(silo->Get_used_storage()) + "/" + QString::number(silo->Get_total_storage()));
}

SiloPage::~SiloPage()
{
    delete ui;
}

void SiloPage::on_pushButton_3_clicked()
{
    switch(silo->Upgrade()){
    case 1:
        //qmessagebox --> "not enough nails for upgrading"
        QMessageBox::critical(this,"NAILS","not enough nails for upgrading");
        break;
    case 2:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COINS","not enough coins for upgrading");
        break;
    case 3:
        //qmessagebox --> "you cannot upgrade silo duo to user's level"
        QMessageBox::critical(this,"LEVEL","you cannot upgrade silo duo to user's level");
        break;
    case 4:
        //qmessagbox --> "timer set for upgrading"
        QMessageBox::information(this,"START","timer set for upgrading");
        break;
    }
}

