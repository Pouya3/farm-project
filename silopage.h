#ifndef SILOPAGE_H
#define SILOPAGE_H

#include <QMainWindow>
#include "silo.h"
#include <QTimer>

namespace Ui {
class SiloPage;
}

class SiloPage : public QMainWindow
{
    Q_OBJECT
private:
    Silo* silo;

public:
    explicit SiloPage(Silo*, QWidget *parent = nullptr);
    ~SiloPage();

private slots:
    void on_pushButton_3_clicked();

    void Set_values();

private:
    Ui::SiloPage *ui;
    QTimer* refresh_timer;
};

#endif // SILOPAGE_H
