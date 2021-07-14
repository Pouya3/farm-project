#include "rankingpage.h"
#include "ui_rankingpage.h"

RankingPage::RankingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RankingPage)
{
    ui->setupUi(this);
    this->setFixedSize(490,640);
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Rank"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Username"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Experience"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Level"));
}

RankingPage::~RankingPage()
{
    delete ui;
}
