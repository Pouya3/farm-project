#ifndef SHOVEL_MARKET_H
#define SHOVEL_MARKET_H

#include <QMainWindow>

namespace Ui {
class Shovel_market;
}

class Shovel_market : public QMainWindow
{
    Q_OBJECT

public:
    explicit Shovel_market(QWidget *parent = nullptr);
    ~Shovel_market();

private:
    Ui::Shovel_market *ui;
};

#endif // SHOVEL_MARKET_H
