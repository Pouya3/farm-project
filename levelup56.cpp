#include "levelup56.h"
#include "ui_levelup56.h"

LevelUp56::LevelUp56(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUp56)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
}

LevelUp56::~LevelUp56()
{
    delete ui;
}
