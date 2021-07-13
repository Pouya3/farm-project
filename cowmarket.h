#ifndef COWMARKET_H
#define COWMARKET_H

#include <QMainWindow>

namespace Ui {
class CowMarket;
}

class CowMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit CowMarket(QWidget *parent = nullptr);
    ~CowMarket();

private:
    Ui::CowMarket *ui;
};

#endif // COWMARKET_H
