#ifndef SPACEPAGE_2_H
#define SPACEPAGE_2_H

#include <QMainWindow>
#include "wheat_land.h"

namespace Ui {
class SpacePage_2;
}

class SpacePage_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpacePage_2(Wheat_land*, QWidget *parent = nullptr);
    ~SpacePage_2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SpacePage_2 *ui;
    Wheat_land* wheat_land;
};

#endif // SPACEPAGE_2_H
