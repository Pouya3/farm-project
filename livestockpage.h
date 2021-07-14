#ifndef LIVESTOCKPAGE_H
#define LIVESTOCKPAGE_H

#include <QMainWindow>
#include "livestock.h"
#include <QTimer>

namespace Ui {
class LivestockPage;
}

class LivestockPage : public QMainWindow
{
    Q_OBJECT
private:
    Livestock* livestock;

public:
    explicit LivestockPage(Livestock*, QWidget *parent = nullptr);
    ~LivestockPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void Set_values();

private:
    Ui::LivestockPage *ui;
    QTimer* refresh_timer;
};

#endif // LIVESTOCKPAGE_H
