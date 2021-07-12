#ifndef MILKMARKET_H
#define MILKMARKET_H

#include <QMainWindow>
#include "store.h"
#include "user.h"

namespace Ui {
class MilkMarket;
}

class MilkMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit MilkMarket(QWidget *parent = nullptr);
    ~MilkMarket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MilkMarket *ui;
    Store* store;
    User* user;
};

#endif // MILKMARKET_H
