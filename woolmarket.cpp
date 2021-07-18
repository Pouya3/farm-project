#include "woolmarket.h"
#include "ui_woolmarket.h"

WoolMarket::WoolMarket(User* _user, Store* _store, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WoolMarket)
{
    ui->setupUi(this);
    this->setFixedSize(1000,460);
    setWindowTitle("Wool market");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    user = _user;
    store = _store;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

WoolMarket::~WoolMarket()
{
    delete ui;
}

void WoolMarket::on_pushButton_clicked()
{
    if(user->Get_level() < 6){
        //qmessagebox --> "you must reach level 6 to sell wool"
        QMessageBox::critical(this,"LEVEL","You must reach level 6 to sell wool");
    }
    else{
        if(ui->spinBox->text().toInt() == 0){
            //qmessagebox --> "number of selling items is 0"
            QMessageBox::critical(this,"0 VALUE","Number of selling items is 0");
        }
        else{
            if(store->Get_object(6) < ui->spinBox->text().toInt()){
                //qmessagebox --> "not enough wool to sell"
                QMessageBox::critical(this,"NOT ENOUGH WOOL","Not enough wool to sell");
            }
            else{
                store->Delete(6, ui->spinBox->text().toInt());
                user->Set_coin(user->Get_coin() + ui->spinBox->text().toInt()*23);
                user->Set_experience(user->Get_experience() + ui->spinBox->text().toInt()*6);

                if(ui->spinBox->text().toInt() == 1){//
                    //qmessagebox --> "wool is sold successfully"
                    QMessageBox::information(this,"SUCCESSFUL TRADE", "1 wool is sold");
                }
                else{
                    //qmessagebox --> "wool is sold successfully"
                    QMessageBox::information(this,"SUCCESSFUL TRADE",
                    QString::number(ui->spinBox->text().toInt()) + " wools are sold");
                }
            }
        }
    }
}

void WoolMarket::Set_values(){
    ui->label->setText(QString::number(store->Get_object(6)));
    ui->label_2->setText(QString::number(store->Get_total_storage() - store->Get_used_storage()));
}
