#include "storepage.h"
#include "ui_storepage.h"
#include <vector>

StorePage::StorePage(Store* _store, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StorePage)
{
    ui->setupUi(this);
    this->setFixedSize(1200,600);

    store = _store;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

StorePage::~StorePage()
{
    delete ui;
}

void StorePage::on_pushButton_clicked()
{
    switch(store->Upgrade()){
    case 1:
        //qmessagebox --> "not enough nails for upgrading"
        QMessageBox::critical(this,"NAILS","not enough nails for upgrading");
        break;
    case 2:
        //qmessagebox --> "not enough shovels for upgrading"
        QMessageBox::critical(this,"SHOVELS","not enough shovels for upgrading");
        break;
    case 3:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COINS","not enough coins for upgrading");
        break;
    case 4:
        //qmessagebox --> "you cannot upgrade store duo to user's level"
        QMessageBox::critical(this,"LEVEL","you cannot upgrade store duo to user's level");
        break;
    case 5:
        //qmessagebox --> "timer set for upgrading"
        QMessageBox::information(this,"LEVEL","timer set for upgrading");
        break;
    case 6:
        QMessageBox::critical(this,"UPGEADING","Store is already in upgrading situation");
        break;
    }
}

void StorePage::Set_values(){
    std::vector<std::pair<int, int>> milk_info_vect;
    std::vector<std::pair<int, int>>::iterator milk_info_iter;
    milk_info_vect = store->Get_milk_info();
    milk_info_iter = milk_info_vect.begin();

    ui->label->setText(QString::number(store->Get_level()));
    ui->label_2->setText(QString::number(store->Get_used_storage()) + "/" + QString::number(store->Get_total_storage()));
    if(milk_info_iter != milk_info_vect.end())
        ui->label_11->setText(QString::number(milk_info_iter->second));
    else
        ui->label_11->setText("0");
    ui->label_3->setText(QString::number(store->Get_object(1)));
    ui->label_4->setText(QString::number(store->Get_object(2)));
    ui->label_5->setText(QString::number(store->Get_object(3)));
    ui->label_7->setText(QString::number(store->Get_object(4)));
    ui->label_6->setText(QString::number(store->Get_object(5)));
    ui->label_8->setText(QString::number(store->Get_object(6)));

    if(store->Get_upgrade_timer() == 0){
        ui->toolButton->setText("--");
    }
    else {
        ui->toolButton->setText(QString::number(store->Get_upgrade_timer()));
    }
}
