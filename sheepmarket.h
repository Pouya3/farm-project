#ifndef SHEEPMARKET_H
#define SHEEPMARKET_H

#include <QMainWindow>
#include "user.h"
#include "aghol.h"
#include <QTimer>

namespace Ui {
class SheepMarket;
}

class SheepMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit SheepMarket(User*, Aghol*, QWidget *parent = nullptr);
    ~SheepMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::SheepMarket *ui;
    Aghol* aghol;
    User* user;
    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;
};

#endif // SHEEPMARKET_H
