#include "spacepage.h"
#include "ui_spacepage.h"

SpacePage::SpacePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpacePage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
}

SpacePage::~SpacePage()
{
    delete ui;
}
