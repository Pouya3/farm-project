#ifndef SHEEPMARKET_H
#define SHEEPMARKET_H

#include <QMainWindow>
#include "user.h"
#include "aghol.h"

namespace Ui {
class SheepMarket;
}

class SheepMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit SheepMarket(QWidget *parent = nullptr);
    ~SheepMarket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SheepMarket *ui;
    Aghol* aghol;
    User* user;
};

#endif // SHEEPMARKET_H
