#ifndef WHEAT_LANDPAGE_H
#define WHEAT_LANDPAGE_H

#include <QMainWindow>
#include "wheat_land.h"

namespace Ui {
class Wheat_landPage;
}

class Wheat_landPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Wheat_landPage(QWidget *parent = nullptr);
    ~Wheat_landPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Wheat_landPage *ui;
    Wheat_land* wheat_land;
};

#endif // WHEAT_LANDPAGE_H
