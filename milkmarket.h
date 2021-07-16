#ifndef MILKMARKET_H
#define MILKMARKET_H

#include <QMainWindow>
#include "store.h"
#include "user.h"
#include <QTimer>

namespace Ui {
class MilkMarket;
}

class MilkMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit MilkMarket(User*, Store*, QWidget *parent = nullptr);
    ~MilkMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::MilkMarket *ui;
    Store* store;
    User* user;
    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;
};

#endif // MILKMARKET_H
