#include "spacepage_2.h"
#include "ui_spacepage_2.h"

SpacePage_2::SpacePage_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpacePage_2)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
}

SpacePage_2::~SpacePage_2()
{
    delete ui;
}

void SpacePage_2::on_pushButton_clicked()
{
    if(ui->spinBox->text().toInt() == 0){
        //qmessagebox --> "area selected for cultivation is 0"
        QMessageBox::critical(this,"0 VALUE","area selected to cultivate is 0");

    }
    else{
        switch (wheat_land->Cultivate(ui->spinBox->text().toInt())) {
        case 2:
            //qmessagebox --> "area selected for cultivation is greater filed's area"
            QMessageBox::critical(this,"GREATER AREA","area selected for cultivation is greater filed's area");
            break;
        case 3:
            //qmessagebox --> " not enough wheat to cultivate"
            QMessageBox::critical(this,"NOT ENOUGH WHEAT","not enough wheat to cultivate");
            break;
        case 4:
            QMessageBox::critical(this,"UPGRADIN","After wheat land upgraded you can ripen");
            break;
        case 5:
            //qmessagebox --> "timer set for ripening"
            QMessageBox::information(this,"START","timer set for ripening");

            break;
        }
    }
}

