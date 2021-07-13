#ifndef EGGMARKET_H
#define EGGMARKET_H

#include <QMainWindow>

namespace Ui {
class eggMarket;
}

class eggMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit eggMarket(QWidget *parent = nullptr);
    ~eggMarket();

private:
    Ui::eggMarket *ui;
};

#endif // EGGMARKET_H
