#ifndef WOOLMARKET_H
#define WOOLMARKET_H

#include <QMainWindow>
#include "user.h"
#include "store.h"
#include <QTimer>

namespace Ui {
class WoolMarket;
}

class WoolMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit WoolMarket(User*, Store*, QWidget *parent = nullptr);
    ~WoolMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::WoolMarket *ui;
    User* user;
    Store* store;
    QTimer* refresh_timer;
};

#endif // WOOLMARKET_H
