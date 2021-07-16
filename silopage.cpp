#include "silopage.h"
#include "ui_silopage.h"

SiloPage::SiloPage(Silo* _silo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SiloPage)
{
    ui->setupUi(this);
    this->setFixedSize(1000,660);
    setWindowTitle("Silo");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    silo = _silo;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

SiloPage::~SiloPage()
{
    delete ui;
}

void SiloPage::on_pushButton_3_clicked()
{
    // return values :
    // 1 == not enough nails
    // 2 == not enough shovels
    // 3 == not enough coins
    // 4 == limit for upgrading duo to user's level
    // 5 == timer set for upgrade (successful upgrade)

    switch(silo->Upgrade()){
    case 1:
        //qmessagebox --> "not enough nails for upgrading"
        QMessageBox::critical(this,"NAILS","not enough nails for upgrading\n " + QString::number(silo->Get_level()*2) + " nails are needed");
        break;
    case 2:
        //qmessagebox --> "not enough shovels for upgrading"
        if(silo->Get_level() == 3){
            QMessageBox::critical(this,"SHOVELS","not enough shovels for upgrading\n1 shovel is needed");
        }
        else {
            QMessageBox::critical(this,"SHOVELS","not enough shovels for upgrading\n " + QString::number(silo->Get_level() - 2) + " shovels are needed");
        }
        break;
    case 3:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COINS","not enough coins for upgrading \n" +
        QString::number(pow(silo->Get_level()*2, 2)*100) + " coins are needed");
        break;
    case 4:
        //qmessagebox --> "you cannot upgrade silo duo to user's level"
        QMessageBox::critical(this,"LEVEL","you cannot upgrade silo duo to user's level \nsilo's level must be one unit less than user's level");
        break;
    case 5:
        //qmessagbox --> "timer set for upgrading"
        QMessageBox::information(this,"START","timer set for upgrading");
        break;
    }
}

void SiloPage::Set_values(){
    ui->label->setText(QString::number(silo->Get_level()));
    ui->label_2->setText(QString::number(silo->Get_used_storage()) + "/" + QString::number(silo->Get_total_storage()));

    if(silo->Get_upgrade_timer() == 0){
        ui->toolButton->setText("--");
    }
    else{
        ui->toolButton->setText(QString::number(silo->Get_upgrade_timer()));
    }
}
