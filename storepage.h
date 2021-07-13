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
private:
    Store* store;

public:
    explicit StorePage(QWidget *parent = nullptr);
    ~StorePage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StorePage *ui;
};

#endif // STOREPAGE_H
