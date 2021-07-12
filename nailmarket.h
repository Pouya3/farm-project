#ifndef NAILMARKET_H
#define NAILMARKET_H

#include <QMainWindow>
#include "store.h"
#include "user.h"

namespace Ui {
class NailMarket;
}

class NailMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit NailMarket(QWidget *parent = nullptr);
    ~NailMarket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NailMarket *ui;
    Store* store;
    User* user;
};

#endif // NAILMARKET_H
