#include "alfalfa_landpage.h"
#include "spacepage.h"
#include "ui_alfalfa_landpage.h"

Alfalfa_landPage::Alfalfa_landPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alfalfa_landPage)
{
    ui->setupUi(this);
    this->setFixedSize(1200,530);
}

Alfalfa_landPage::~Alfalfa_landPage()
{
    delete ui;
}

void Alfalfa_landPage::on_pushButton_4_clicked()
{
    SpacePage* s=new SpacePage;
    s->show();
    this->close();
}

