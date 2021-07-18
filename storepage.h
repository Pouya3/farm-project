#ifndef STOREPAGE_H
#define STOREPAGE_H

#include <QMainWindow>
#include "store.h"
#include <QTimer>

namespace Ui {
class StorePage;
}

class StorePage : public QMainWindow
{
    Q_OBJECT
public:
    explicit StorePage(Store*, QWidget *parent = nullptr);
    ~StorePage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StorePage *ui;
    Store* store;

    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;

private slots:
    void Set_values();
};

#endif // STOREPAGE_H
