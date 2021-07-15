#ifndef ALFALFAMARKET_H
#define ALFALFAMARKET_H

#include <QMainWindow>
#include "user.h"
#include "store.h"
#include <QTimer>

namespace Ui {
class AlfalfaMarket;
}

class AlfalfaMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlfalfaMarket(User*, Store*, QWidget *parent = nullptr);
    ~AlfalfaMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::AlfalfaMarket *ui;
    User* user;
    Store* store;
    QTimer* refresh_timer;
};

#endif // ALFALFAMARKET_H
