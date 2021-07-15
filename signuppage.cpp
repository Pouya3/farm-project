#include "signuppage.h"
#include "ui_signuppage.h"
#include "mainwindow.h"
#include "loginpage.h"
#include <iostream>
signupPage::signupPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signupPage)
{
    ui->setupUi(this);
    this->setFixedSize(880,600);
    setWindowTitle("Sign up");

    pix = new QPixmap(":/new/prefix1/img/logo.jpg");
    icon = new QIcon(*pix);
    this->setWindowIcon(*icon);

    //pushButton_s->setShortcut(tr("Enter"));
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
                        if(!ui->lineEdit_s_5->text().isEmpty() ){ // email field is filled (successful signup)

                            QString ema = ui->lineEdit_s_5->text();
                            int adad=0;
                            for(int i=0; i<ema.length(); i++) {
                                if(ema[i]=='@')
                                {
                                    adad=1;
                                    break;
                                }
                            }

                            if(adad==1){
                                if(ui->lineEdit_s_3->text().length()>=4){
                                    QString passwo = ui->lineEdit_s_3->text();
                                    int digit=0,word=0;
                                    for ( const auto& character : passwo ) {
                                        if ( character.isUpper() )
                                        {
                                            word++;
                                        }
                                        else if ( character.isLower() )
                                        {
                                            word++;
                                        }
                                        else if ( character.isDigit() )
                                        {
                                            digit++;
                                        }
                                    }
                                    if(word!=0 && digit!=0){
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
                                            ui->lineEdit_s_2->setPlaceholderText("*username exists*");
                                        }
                                    }
                                    else {
                                        ui->lineEdit_s_3->clear();
                                        ui->lineEdit_s_3->setPlaceholderText("*Password is weak*");
                                    }
                                }
                                else {
                                    ui->lineEdit_s_3->clear();
                                    ui->lineEdit_s_3->setPlaceholderText("*Password is weak*");
                                }
                            }
                            else{
                                ui->lineEdit_s_5->clear();
                                ui->lineEdit_s_5->setPlaceholderText("*Email is incorrect*");
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

