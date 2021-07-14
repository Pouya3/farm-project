#ifndef AGHOLPAGE_H
#define AGHOLPAGE_H

#include <QMainWindow>
#include "aghol.h"
#include <QTimer>

namespace Ui {
class AgholPage;
}

class AgholPage : public QMainWindow
{
    Q_OBJECT
private:
    Aghol* aghol;

public:
    explicit AgholPage( Aghol*, QWidget *parent = nullptr);
    ~AgholPage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void Set_values();

private:
    Ui::AgholPage *ui;
    QTimer* refresh_timer;
};

#endif // AGHOLPAGE_H
