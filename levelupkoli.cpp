#include "levelupkoli.h"
#include "ui_levelupkoli.h"

LevelUpKoli::LevelUpKoli(int _previous_level, int _current_level, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelUpKoli)
{
    ui->setupUi(this);
    this->setFixedSize(665,670);
    setWindowTitle("Level up");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    ui->label->setText(QString::number(_previous_level));
    ui->label_2->setText(QString::number(_current_level));
}

LevelUpKoli::~LevelUpKoli()
{
    delete ui;
}
