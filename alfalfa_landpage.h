#ifndef ALFALFA_LANDPAGE_H
#define ALFALFA_LANDPAGE_H

#include <QMainWindow>
#include "alfalfa_land.h"
#include <QTimer>

namespace Ui {
class Alfalfa_landPage;
}

class Alfalfa_landPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alfalfa_landPage(Alfalfa_land*, QWidget *parent = nullptr);
    ~Alfalfa_landPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void Set_values();


private:
    Ui::Alfalfa_landPage *ui;
    Alfalfa_land* alfalfa_land;
    QTimer* refresh_timer;
};

#endif // ALFALFA_LANDPAGE_H
