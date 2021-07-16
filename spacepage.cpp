#include "spacepage.h"
#include "ui_spacepage.h"
#include <QMessageBox>

SpacePage::SpacePage(Alfalfa_land* _alfalfa_land, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpacePage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
    setWindowTitle("Space");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    alfalfa_land = _alfalfa_land;
}

SpacePage::~SpacePage()
{
    delete ui;
}

void SpacePage::on_pushButton_clicked()
{
    if(ui->spinBox->text().toInt() == 0){
        //qmessagebox --> "area selected to cultivate is 0"
        QMessageBox::critical(this,"0 VALUE","area selected to cultivate is 0");
    }
    else {
        switch(alfalfa_land->Cultivate(ui->spinBox->text().toInt())){
        case 5:
            //qmessagebox --> "area selected to cultivate is greater than total area"
            QMessageBox::critical(this,"AREA","area selected to cultivate is greater than total area");
            break;
        case 6:
            //qmessagebox --> "not enough alfalfa"
            QMessageBox::critical(this,"NOT ENOUGH ALFALFA","not enough alfalfa to cultivate");
            break;
        case 7:
            //qmessagebox --> "timer set for ripening"
            QMessageBox::information(this,"START","timer set for ripening");
            this->close();
            break;
        }
    }
}

