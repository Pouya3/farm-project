#ifndef WHEAT_LANDWINDOW_H
#define WHEAT_LANDWINDOW_H

#include <QWidget>
#include "wheat_land.h"

#define WHEAT_LAND ":/new/prefix1/img/wheat land.jpg"

namespace Ui {
class Wheat_landWindow;
}

class Wheat_landWindow : public QWidget
{
    Q_OBJECT

public:
    explicit Wheat_landWindow(Wheat_land* _wheat_land, QWidget *parent = nullptr);
    ~Wheat_landWindow();

public slots:
    void Harvest();
    void Upgrade();

private:
    Ui::Wheat_landWindow *ui;

    Wheat_land* wheat_land;
};

#endif // WHEAT_LANDWINDOW_H
