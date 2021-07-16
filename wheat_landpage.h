#ifndef WHEAT_LANDPAGE_H
#define WHEAT_LANDPAGE_H

#include <QMainWindow>
#include "wheat_land.h"
#include <QTimer>

namespace Ui {
class Wheat_landPage;
}

class Wheat_landPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wheat_landPage(Wheat_land*, QWidget *parent = nullptr);
    ~Wheat_landPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void Set_values();

private:
    Ui::Wheat_landPage *ui;
    Wheat_land* wheat_land;

    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;
};

#endif // WHEAT_LANDPAGE_H
