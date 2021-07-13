#ifndef WHEATMARKET_H
#define WHEATMARKET_H

#include <QMainWindow>

namespace Ui {
class WheatMarket;
}

class WheatMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit WheatMarket(QWidget *parent = nullptr);
    ~WheatMarket();

private:
    Ui::WheatMarket *ui;
};

#endif // WHEATMARKET_H
