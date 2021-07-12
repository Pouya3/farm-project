#ifndef WOOLMARKET_H
#define WOOLMARKET_H

#include <QMainWindow>
#include "user.h"
#include "store.h"

namespace Ui {
class WoolMarket;
}

class WoolMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit WoolMarket(QWidget *parent = nullptr);
    ~WoolMarket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WoolMarket *ui;
    User* user;
    Store* store;
};

#endif // WOOLMARKET_H
