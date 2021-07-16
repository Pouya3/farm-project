#ifndef WHEATMARKET_H
#define WHEATMARKET_H

#include <QMainWindow>
#include "user.h"
#include "silo.h"
#include <QTimer>

namespace Ui {
class WheatMarket;
}

class WheatMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit WheatMarket(User*, Silo*, QWidget *parent = nullptr);
    ~WheatMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::WheatMarket *ui;
    User* user;
    Silo* silo;
    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;
};

#endif // WHEATMARKET_H
