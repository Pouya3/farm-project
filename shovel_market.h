#ifndef SHOVEL_MARKET_H
#define SHOVEL_MARKET_H

#include <QMainWindow>
#include "store.h"
#include "user.h"
#include <QTimer>

namespace Ui {
class Shovel_market;
}

class Shovel_market : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shovel_market(User*, Store*, QWidget *parent = nullptr);
    ~Shovel_market();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::Shovel_market *ui;
    Store* store;
    User* user;
    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;
};

#endif // SHOVEL_MARKET_H
