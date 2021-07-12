#ifndef SHOVEL_MARKET_H
#define SHOVEL_MARKET_H

#include <QMainWindow>
#include "store.h"
#include "user.h"

namespace Ui {
class Shovel_market;
}

class Shovel_market : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shovel_market(QWidget *parent = nullptr);
    ~Shovel_market();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Shovel_market *ui;
    Store* store;
    User* user;
};

#endif // SHOVEL_MARKET_H
