#include "signuppage.h"
#include "ui_signuppage.h"
#include "mainwindow.h"
#include "loginpage.h"
signupPage::signupPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signupPage)
{
    ui->setupUi(this);
    this->setFixedSize(880,600);
}

signupPage::~signupPage()
{
    delete ui;
}

void signupPage::on_pushButton_s_clicked()
{
    if(!ui->lineEdit_s->text().isEmpty()){ // name field is filled
        if(!ui->lineEdit_s_2->text().isEmpty()){ // username field is filled
            if(!ui->lineEdit_s_3->text().isEmpty()){ // password field is filled
                if(!ui->lineEdit_s_4->text().isEmpty()){ // password rep field is filled
                    if(ui->lineEdit_s_3->text() == ui->lineEdit_s_4->text()){ // password repeat is correct
                        if(!ui->lineEdit_s_5->text().isEmpty()){ // email field is filled (successful signup)
                            if(Create_new_user_files(ui->lineEdit_s_2->text(), ui->lineEdit_s->text(), ui->lineEdit_s_3->text(), ui->lineEdit_s_5->text())){
                                // qmessagebox for account created successfully
                                QMessageBox::information(this,"SIGN UP","Account created successfully");
                                // goto first window or anything
                                LoginPage *lo=new LoginPage;
                                lo->show();
                                this->close();
                            }
                            else{
                                ui->lineEdit_s_2->clear();
                                ui->lineEdit_s_2->setPlaceholderText("username exists");
                            }
                        }
                        else{
                            ui->lineEdit_s_5->setPlaceholderText("*fill this field*");
                        }
                    }
                    else{
                        ui->lineEdit_s_4->clear();
                        ui->lineEdit_s_4->setPlaceholderText("*wrong repeat*");
                    }
                }
                else{
                    ui->lineEdit_s_4->setPlaceholderText("*fill this field*");
                }
            }
            else{
                ui->lineEdit_s_3->setPlaceholderText("*fill this field*");
            }
        }
        else{
            ui->lineEdit_s_2->setPlaceholderText("*fill this field*");
        }
    }
    else{
        ui->lineEdit_s->setPlaceholderText("*fill this field*");
    }
}


void signupPage::on_pushButton_s_2_clicked()
{
    MainWindow* w=new MainWindow;
    w->show();
    this->close();
}

