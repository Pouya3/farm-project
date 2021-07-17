#ifndef NAILMARKET_H
#define NAILMARKET_H

#include <QMainWindow>
#include "store.h"
#include "user.h"
#include <QTimer>

namespace Ui {
class NailMarket;
}

class NailMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit NailMarket(User*, Store*, QWidget *parent = nullptr);
    ~NailMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::NailMarket *ui;
    Store* store;
    User* user;
    QTimer* refresh_timer;
};

#endif // NAILMARKET_H
