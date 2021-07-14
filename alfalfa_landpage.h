#ifndef ALFALFA_LANDPAGE_H
#define ALFALFA_LANDPAGE_H

#include <QMainWindow>
#include <alfalfa_land.h>

namespace Ui {
class Alfalfa_landPage;
}

class Alfalfa_landPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alfalfa_landPage(QWidget *parent = nullptr);
    ~Alfalfa_landPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

<<<<<<< HEAD
    void on_pushButton_3_clicked();
=======
    void on_pushButton_5_clicked();
>>>>>>> 3281c27008d3ffd736b38a0556cf1156e1c84932

private:
    Ui::Alfalfa_landPage *ui;
    Alfalfa_land* alfalfa_land;
};

#endif // ALFALFA_LANDPAGE_H
