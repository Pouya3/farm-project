#include "loginpage.h"
#include "ui_loginpage.h"
#include "user.h"

LoginPage::LoginPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setFixedSize(880,600);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_pushButton_l_clicked()
{
    if(!ui->lineEdit_l->text().isEmpty()){ // username field is filled
        if(!ui->lineEdit_l_2->text().isEmpty()){ // password field is filled

            User *user = new User;
            if(Login_user(ui->lineEdit_l->text(), ui->lineEdit_l_2->text(), user) == 0){
                ui->lineEdit_l->clear();
                ui->lineEdit_l->setPlaceholderText("username not found");
                delete user;
            }
            else if(Login_user(ui->lineEdit_l->text(), ui->lineEdit_l_2->text(), user) == 1){
                ui->lineEdit_l_2->clear();
                ui->lineEdit_l_2->setPlaceholderText("wrong password");
                delete user;
            }
            else{
                // login successfully
                // goto game window
                // NOTE : pass user to game window
            }
        }
        else{
            ui->lineEdit_l_2->setPlaceholderText("*fill this filed*");
        }
    }
    else{
        ui->lineEdit_l->setPlaceholderText("*fill this filed*");
    }
}

