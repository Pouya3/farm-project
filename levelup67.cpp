#include "levelup67.h"
#include "ui_levelup67.h"

LevelUp67::LevelUp67(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUp67)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
    setWindowTitle("Level up");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);
}

LevelUp67::~LevelUp67()
{
    delete ui;
}
