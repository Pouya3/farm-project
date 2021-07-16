#include "wheat_landpage.h"
#include "spacepage_2.h"
#include "ui_wheat_landpage.h"

Wheat_landPage::Wheat_landPage(Wheat_land* _wheat_land, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wheat_landPage)
{
    ui->setupUi(this);
    this->setFixedSize(1250,550);
    setWindowTitle("Wheat land");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    wheat_land = _wheat_land;

    refresh_timer = new QTimer(this);
    refresh_timer->start(50);
    connect(refresh_timer, SIGNAL(timeout()), this, SLOT(Set_values()));
}

Wheat_landPage::~Wheat_landPage()
{
    delete ui;
}

void Wheat_landPage::on_pushButton_clicked()
{    
    if(wheat_land->Get_upgrade_timer() > 0){
        //qmessagebox --> "wheat land is upgrading"
        QMessageBox::critical(this,"UPGRADING","wheat land is upgrading");
    }
    else if(wheat_land->Get_cultivation_status() != 0){
        //qmessagebox --> "you have to wait for wheats to ripen and harvest them to cultivate"
        QMessageBox::critical(this,"CULTIVATED","You have to wait for wheats to ripen and harvest them to cultivate");
    }
    else{
        SpacePage_2* s=new SpacePage_2(wheat_land);
        s->show();
        this->close();
    }
}


void Wheat_landPage::on_pushButton_3_clicked()
{
    switch (wheat_land->Upgrade()) {
    case 1:
        //qmessagebox --> "Wheat land is already in upgrading situation"
        QMessageBox::critical(this,"UPGEADING","Wheat land is already in upgrading situation");
        break;
    case 2:
        //qmessagebox --> "you have to wait for wheats to ripen and harvest them to upgrade"
        QMessageBox::critical(this,"WAIT","You have to wait for wheats to ripen and harvest them to upgrade");
        break;
    case 3:
        //qmessagebox --> "not enough shovels for upgrading"
        QMessageBox::critical(this,"SHOVEL","Not enough shovels for upgrading \n1 shovel is needed");
        break;
    case 4:
        //qmessagebox --> "not enough coins for upgrading"
        QMessageBox::critical(this,"COIN","Not enough coins for upgrading \n5 coins are needed");
        break;
    case 5:
        //qmessagebox --> "you cannot upgrade wheat land until you reach level 2"
        QMessageBox::critical(this,"LEVEL","You cannot upgrade wheat land until you reach level 2");
        break;
    case 6:
        //qmessagebox --> "timer set for upgrading"
        QMessageBox::information(this,"START","Timer set for upgrading");
        break;
    }
}


void Wheat_landPage::on_pushButton_2_clicked()
{
    switch (wheat_land->Harvest()) {
    case 1:
        //qmessagebox --> "nothing to harvest"
        QMessageBox::critical(this,"EMPTY","Nothing to harvest");
        break;
    case 2:
        //qmessagebox --> "not enough space in silo"
        QMessageBox::critical(this,"SPACE","Not enough space in silo");
        break;
    case 3:
        //messagebox --> "harvested successfully"
        QMessageBox::information(this,"HARVESTED","Harvested successfully");
        break;
    }
}

void Wheat_landPage::Set_values(){
    ui->label->setText(QString::number(wheat_land->Get_level()));
    ui->label_2->setText(QString::number(wheat_land->Get_cultivated_area()) + "/" + QString::number(wheat_land->Get_total_area()));

    if(wheat_land->Get_upgrade_timer() > 0){
        ui->label_3->setText("Upgrading..." + QString::number(wheat_land->Get_upgrade_timer()));
    }
    else if(wheat_land->Get_cultivation_status() == 0){
        ui->label_3->setText("Ready to\n cultivate");
    }
    else if(wheat_land->Get_cultivation_status() == 1){
        ui->label_3->setText("Ripening..." + QString::number(wheat_land->Get_ripening_timer()));
    }
    else{
        ui->label_3->setText("Ripe");
    }
}
