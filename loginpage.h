#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include "file_functions.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_pushButton_l_clicked();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
