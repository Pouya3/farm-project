#ifndef CHICKENMARKET_H
#define CHICKENMARKET_H

#include <QMainWindow>
#include "aviculture.h"
#include "user.h"


namespace Ui {
class ChickenMarket;
}

class ChickenMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChickenMarket(QWidget *parent = nullptr);
    ~ChickenMarket();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChickenMarket *ui;
    User* user;
    Aviculture* aviculture;
};

#endif // CHICKENMARKET_H
