#ifndef STOREPAGE_H
#define STOREPAGE_H

#include <QMainWindow>
#include "store.h"

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
};

#endif // STOREPAGE_H
