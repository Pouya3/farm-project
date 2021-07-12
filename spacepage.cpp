#include "spacepage.h"
#include "ui_spacepage.h"

SpacePage::SpacePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpacePage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);
}

SpacePage::~SpacePage()
{
    delete ui;
}

void SpacePage::on_pushButton_clicked()
{
    if(ui->spinBox->text().toInt() == 0){
        //qmessagebox --> "selected area to cultivate is 0"
    }
    else {
        switch(alfalfa_land->Cultivate(ui->spinBox->text().toInt())){
        case 3:
            //qmessagebox --> "not enough alfalfa"
            break;
        case 4:
            //qmessagebox --> "timer set for cultivation"
            this->close();
            break;
        }
    }
}

