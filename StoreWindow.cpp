#include "StoreWindow.h"
#include "ui_StoreWindow.h"

#include <QPixmap>
#include <QSize>
#include <qmessagebox.h>

StoreWindow::StoreWindow(Store* _store, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StoreWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Store");

    QPixmap background(STORE);
    ui->background_label->setPixmap(background.scaled(800,450,Qt::KeepAspectRatio));

    QPixmap shovel(SHOVEL);
    ui->shovel_label->setPixmap(shovel.scaled(60,60,Qt::KeepAspectRatio));

    QPixmap nail(NAIL);
    ui->nail_label->setPixmap(nail.scaled(55,55,Qt::KeepAspectRatio));

    QPixmap alfalfa(ALFALFA);
    ui->alfalfa_label->setPixmap(alfalfa.scaled(60,60,Qt::KeepAspectRatio));

    QPixmap milk(MILK);
    ui->milk_label->setPixmap(milk.scaled(60,60,Qt::KeepAspectRatio));

    QPixmap egg(EGG);
    ui->egg_label->setPixmap(egg.scaled(50,50,Qt::KeepAspectRatio));

    QPixmap wool(WOOL);
    ui->wool_label->setPixmap(wool.scaled(60,60,Qt::KeepAspectRatio));

    store = _store;

    ui->level_number_label->setText(QString::number(store->Get_level()));
    ui->number_of_shovels_label->setText(QString::number(store->Get_object(1)));
    ui->number_of_nails_label->setText(QString::number(store->Get_object(2)));
    ui->number_of_alfalfas_label->setText(QString::number(store->Get_object(3)));
    ui->number_of_milks_label->setText(QString::number(store->Get_object(5)));
    ui->number_of_eggs_label->setText(QString::number(store->Get_object(4)));
    ui->number_of_wools_label->setText(QString::number(store->Get_object(6)));

    ////////////////////////////////

    connect(ui->upgrade_button, SIGNAL(clicked()), this, SLOT(Upgrade()));
}

StoreWindow::~StoreWindow()
{
    delete ui;
}

void StoreWindow::Upgrade(){
   store->Upgrade();
}
