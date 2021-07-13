#ifndef MARKETPAGE_H
#define MARKETPAGE_H

#include <QMainWindow>

namespace Ui {
class MarketPage;
}

class MarketPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MarketPage(QWidget *parent = nullptr);
    ~MarketPage();

private:
    Ui::MarketPage *ui;
};

#endif // MARKETPAGE_H
