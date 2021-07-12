#ifndef COWMARKET_H
#define COWMARKET_H

#include <QMainWindow>
#include "livestock.h"
#include "user.h"

namespace Ui {
class CowMarket;
}

class CowMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit CowMarket(QWidget *parent = nullptr);
    ~CowMarket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CowMarket *ui;
    User* user;
    Livestock* livestock;
};

#endif // COWMARKET_H
