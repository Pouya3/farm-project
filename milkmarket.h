#ifndef MILKMARKET_H
#define MILKMARKET_H

#include <QMainWindow>

namespace Ui {
class MilkMarket;
}

class MilkMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit MilkMarket(QWidget *parent = nullptr);
    ~MilkMarket();

private:
    Ui::MilkMarket *ui;
};

#endif // MILKMARKET_H
