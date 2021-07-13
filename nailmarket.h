#ifndef NAILMARKET_H
#define NAILMARKET_H

#include <QMainWindow>

namespace Ui {
class NailMarket;
}

class NailMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit NailMarket(QWidget *parent = nullptr);
    ~NailMarket();

private:
    Ui::NailMarket *ui;
};

#endif // NAILMARKET_H
