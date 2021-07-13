#ifndef SHEEPMARKET_H
#define SHEEPMARKET_H

#include <QMainWindow>

namespace Ui {
class SheepMarket;
}

class SheepMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit SheepMarket(QWidget *parent = nullptr);
    ~SheepMarket();

private:
    Ui::SheepMarket *ui;
};

#endif // SHEEPMARKET_H
