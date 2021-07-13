#ifndef LIVESTOCKPAGE_H
#define LIVESTOCKPAGE_H

#include <QMainWindow>
#include "livestock.h"

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

private:
    Ui::LivestockPage *ui;
};

#endif // LIVESTOCKPAGE_H
