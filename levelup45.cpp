#include "levelup45.h"
#include "ui_levelup45.h"

LevelUp45::LevelUp45(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUp45)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
    setWindowTitle("Level up");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);
}

LevelUp45::~LevelUp45()
{
    delete ui;
}
