#include "levelup34.h"
#include "ui_levelup34.h"

LevelUp34::LevelUp34(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUp34)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
    setWindowTitle("Level up");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);
}

LevelUp34::~LevelUp34()
{
    delete ui;
}
