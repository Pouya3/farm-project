#ifndef ALFALFA_LANDPAGE_H
#define ALFALFA_LANDPAGE_H

#include <QMainWindow>

namespace Ui {
class Alfalfa_landPage;
}

class Alfalfa_landPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alfalfa_landPage(QWidget *parent = nullptr);
    ~Alfalfa_landPage();

private:
    Ui::Alfalfa_landPage *ui;
};

#endif // ALFALFA_LANDPAGE_H
