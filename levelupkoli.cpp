#include "levelupkoli.h"
#include "ui_levelupkoli.h"

LevelUpKoli::LevelUpKoli(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUpKoli)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
}

LevelUpKoli::~LevelUpKoli()
{
    delete ui;
}
