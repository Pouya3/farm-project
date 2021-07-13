#ifndef SPACEPAGE_H
#define SPACEPAGE_H

#include <QMainWindow>
#include "alfalfa_land.h"

namespace Ui {
class SpacePage;
}

class SpacePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpacePage(Alfalfa_land*, QWidget *parent = nullptr);
    ~SpacePage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SpacePage *ui;
    Alfalfa_land* alfalfa_land;
};

#endif // SPACEPAGE_H
