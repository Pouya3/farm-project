#include "Wheat_landWindow.h"
#include "ui_Wheat_landWindow.h"

#include <qsize.h>
#include <qpixmap.h>

Wheat_landWindow::Wheat_landWindow(Wheat_land* _wheat_land, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wheat_landWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Wheat land");

    QPixmap background(WHEAT_LAND);
    ui->background_label->setPixmap(background.scaled(650,450, Qt::KeepAspectRatio));

    wheat_land = _wheat_land;

    if(wheat_land->Get_status() == 0){
        ui->status_number_label->setText("Not Cultivated");
        ui->DAYS_TO_WAIT_label->hide();
        ui->days_t_wait_number_label->hide();
        ui->harvest_button->hide();
    }
    else if(wheat_land->Get_status() == 1){
        ui->status_number_label->setText("Waiting for wheats to get ripe");
        ui->DAYS_TO_WAIT_label->show();
        ui->days_t_wait_number_label->show();
        // time
        ui->harvest_button->hide();
    }
    else {
        ui->status_number_label->setText("Ripe wheats");
        ui->DAYS_TO_WAIT_label->hide();
        ui->days_t_wait_number_label->hide();
        ui->harvest_button->show();
    }
    ui->area_number_label->setText(QString::number(wheat_land->Get_cultivated()));
    ui->level_number_label->setText(QString::number(wheat_land->Get_level()));
    ui->cultivated_area_number_label->setText(QString::number(wheat_land->Get_cultivated()));

    ////////////////////////////

    connect(ui->upgrade_button, SIGNAL(clicked()), this, SLOT(Upgrade()));
    connect(ui->harvest_button, SIGNAL(clicked()), this, SLOT(Harvest()));
}

Wheat_landWindow::~Wheat_landWindow()
{
    delete ui;
}

void Wheat_landWindow::Upgrade(){
    wheat_land->Upgrade();
}

void Wheat_landWindow::Harvest(){
    wheat_land->Harvesting(wheat_land->Get_cultivated());
}
