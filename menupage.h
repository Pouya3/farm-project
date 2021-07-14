#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QMainWindow>
#include "user.h"
#include "mainpage.h"

namespace Ui {
class MenuPage;
}

class MenuPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuPage(QWidget *parent = nullptr);
    ~MenuPage();

private slots:
<<<<<<< HEAD
    void on_pushButton_3_clicked();
=======
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
>>>>>>> 8c6eb99a17f2a0eae3dd5f19c98a840d82d207aa

private:
    Ui::MenuPage *ui;
    User* user;
    MainPage* mainpage;
};

#endif // MENUPAGE_H
