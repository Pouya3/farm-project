#ifndef WHEATMARKET_H
#define WHEATMARKET_H

#include <QMainWindow>
#include "user.h"
#include "silo.h"

namespace Ui {
class WheatMarket;
}

class WheatMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit WheatMarket(QWidget *parent = nullptr);
    ~WheatMarket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WheatMarket *ui;
    User* user;
    Silo* silo;
};

#endif // WHEATMARKET_H
