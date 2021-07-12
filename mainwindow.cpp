#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signuppage.h"
#include "loginpage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(880,630);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    signupPage* s=new signupPage;
    s->show();
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    LoginPage* l=new LoginPage;
    l->show();
    this->close();
}

