#ifndef COWMARKET_H
#define COWMARKET_H

#include <QMainWindow>
#include "livestock.h"
#include "user.h"
#include <QTimer>

namespace Ui {
class CowMarket;
}

class CowMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit CowMarket(User*, Livestock*, QWidget *parent = nullptr);
    ~CowMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::CowMarket *ui;
    User* user;
    Livestock* livestock;
    QTimer* refresh_timer;
};

#endif // COWMARKET_H
