#ifndef CHICKENMARKET_H
#define CHICKENMARKET_H

#include <QMainWindow>

namespace Ui {
class ChickenMarket;
}

class ChickenMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChickenMarket(QWidget *parent = nullptr);
    ~ChickenMarket();

private:
    Ui::ChickenMarket *ui;
};

#endif // CHICKENMARKET_H
