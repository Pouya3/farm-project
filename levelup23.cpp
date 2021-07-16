#include "levelup23.h"
#include "ui_levelup23.h"

LevelUp23::LevelUp23(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUp23)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
    setWindowTitle("Level up");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);
}

LevelUp23::~LevelUp23()
{
    delete ui;
}
