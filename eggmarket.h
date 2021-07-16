#ifndef EGGMARKET_H
#define EGGMARKET_H

#include <QMainWindow>
#include "store.h"
#include "user.h"
#include <QTimer>

namespace Ui {
class eggMarket;
}

class eggMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit eggMarket(User*, Store*, QWidget *parent = nullptr);
    ~eggMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::eggMarket *ui;
    Store* store;
    User* user;
    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;
};

#endif // EGGMARKET_H
