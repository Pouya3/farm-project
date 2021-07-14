#include "wheat_landpage.h"
#include "spacepage.h"
#include "ui_wheat_landpage.h"

Wheat_landPage::Wheat_landPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wheat_landPage)
{
    ui->setupUi(this);
    this->setFixedSize(1250,550);
}

Wheat_landPage::~Wheat_landPage()
{
    delete ui;
}

void Wheat_landPage::on_pushButton_clicked()
{
    SpacePage* s=new SpacePage;
    s->show();
    this->close();
}

