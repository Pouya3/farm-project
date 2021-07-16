#include "levelup12.h"
#include "ui_levelup12.h"

LevelUp12::LevelUp12(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUp12)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
    setWindowTitle("Level up");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);
}

LevelUp12::~LevelUp12()
{
    delete ui;
}
