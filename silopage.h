#ifndef SILOPAGE_H
#define SILOPAGE_H

#include <QMainWindow>
#include "silo.h"

namespace Ui {
class SiloPage;
}

class SiloPage : public QMainWindow
{
    Q_OBJECT
private:
    Silo* silo;

public:
    explicit SiloPage(QWidget *parent = nullptr);
    ~SiloPage();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::SiloPage *ui;
};

#endif // SILOPAGE_H
