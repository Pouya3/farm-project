#include "eggmarket.h"
#include "ui_eggmarket.h"

eggMarket::eggMarket(User* _user, Store* _store, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eggMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);
    setWindowTitle("Egg market");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    user = _user;
    store = _store;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

eggMarket::~eggMarket()
{
    delete ui;
}

void eggMarket::on_pushButton_clicked()
{
    if(ui->spinBox->text().toInt() == 0){
        //qmessagebox --> "number of selling items is 0"
        QMessageBox::critical(this,"0 VALUE","number of selling items is 0");
    }
    else{
        if(store->Get_object(4) < ui->spinBox->text().toUInt()){
            //qmessagebox --> "not enough eggs to sell"
            QMessageBox::critical(this,"NOT ENOUGH EGGS","not enough eggs to sell");
        }
        else{
            store->Delete(4, ui->spinBox->text().toInt());
            user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*8);
            user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*6);
        }
    }
}

void eggMarket::Set_values(){
    ui->label->setText(QString::number(store->Get_object(4)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}
