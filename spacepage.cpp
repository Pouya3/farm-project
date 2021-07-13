#include "spacepage.h"
#include "ui_spacepage.h"
#include <QMessageBox>

SpacePage::SpacePage(Alfalfa_land* _alfalfa_land, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpacePage)
{
    ui->setupUi(this);
    this->setFixedSize(900,600);

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
        case 3:
            //qmessagebox --> "not enough alfalfa"
            QMessageBox::critical(this,"NOT ENOUGH ALFALFA","not enough alfalfa to cultivate");
            break;
        case 4:
            QMessageBox::critical(this,"UPGRADIN","After alfalfa land upgraded you can ripen");
            break;
        case 5:
            //qmessagebox --> "timer set for ripening"
            QMessageBox::information(this,"START","timer set for ripening");
            this->close();
            break;
        }
    }
}

