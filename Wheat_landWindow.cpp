#include "Wheat_landWindow.h"
#include "ui_Wheat_landWindow.h"



Wheat_landWindow::Wheat_landWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wheat_landWindow)
{
    ui->setupUi(this);

}

Wheat_landWindow::~Wheat_landWindow()
{
    delete ui;
}


