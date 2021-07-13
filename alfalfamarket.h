#ifndef ALFALFAMARKET_H
#define ALFALFAMARKET_H

#include <QMainWindow>

namespace Ui {
class AlfalfaMarket;
}

class AlfalfaMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlfalfaMarket(QWidget *parent = nullptr);
    ~AlfalfaMarket();

private:
    Ui::AlfalfaMarket *ui;
};

#endif // ALFALFAMARKET_H
