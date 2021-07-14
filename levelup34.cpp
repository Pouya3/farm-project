#include "levelup34.h"
#include "ui_levelup34.h"

LevelUp34::LevelUp34(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUp34)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
}

LevelUp34::~LevelUp34()
{
    delete ui;
}
