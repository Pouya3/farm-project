#ifndef CHICKENMARKET_H
#define CHICKENMARKET_H

#include <QMainWindow>
#include "aviculture.h"
#include "user.h"
#include <QTimer>


namespace Ui {
class ChickenMarket;
}

class ChickenMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChickenMarket(User*, Aviculture*, QWidget *parent = nullptr);
    ~ChickenMarket();

private slots:
    void on_pushButton_clicked();

    void Set_values();

private:
    Ui::ChickenMarket *ui;
    User* user;
    Aviculture* aviculture;
    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;
};

#endif // CHICKENMARKET_H
