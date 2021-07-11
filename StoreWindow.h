#ifndef STOREWINDOW_H
#define STOREWINDOW_H

#include <QWidget>
#include "store.h"

#define STORE ":/new/prefix1/img/store.jpg"
#define SHOVEL ":/new/prefix1/img/shovel.png"
#define NAIL ":/new/prefix1/img/nail.png"
#define ALFALFA ":/new/prefix1/img/alfalfa.png"
#define EGG ":/new/prefix1/img/egg.png"
#define MILK ":/new/prefix1/img/milk.png"
#define WOOL ":/new/prefix1/img/wool.png"

namespace Ui {
class StoreWindow;
}

class StoreWindow : public QWidget
{
    Q_OBJECT

public:
    StoreWindow(Store* _store, QWidget *parent = nullptr);
    ~StoreWindow();

public slots:
    void Upgrade();

private:
    Ui::StoreWindow *ui;
    Store* store;
};

#endif // STOREWINDOW_H
