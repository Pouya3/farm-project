#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QMainWindow>
#include "user.h"
#include "mainpage.h"
#include <QMultiMap>

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
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MenuPage *ui;
    User* user;
    MainPage* mainpage;
    QMultiMap<int,QString> users_for_ranking;
};

#endif // MENUPAGE_H
