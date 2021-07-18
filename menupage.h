#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QMainWindow>
#include "user.h"
#include "mainpage.h"
#include <QMultiMap>
#include <QTimer>
#include <vector>


namespace Ui {
class MenuPage;
}

class MenuPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuPage(User*, MainPage*, QWidget *parent = nullptr);
    ~MenuPage();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void Set_values();

    void on_pushButton_4_clicked();

private:
    Ui::MenuPage *ui;
    User* user;
    MainPage* mainpage;
    std::vector<std::pair<int, QString>> users_for_ranking;
    QTimer* refresh_timer;
};

#endif // MENUPAGE_H
