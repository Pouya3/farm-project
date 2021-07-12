#ifndef WHEAT_LANDPAGE_H
#define WHEAT_LANDPAGE_H

#include <QMainWindow>

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

private:
    Ui::Wheat_landPage *ui;
};

#endif // WHEAT_LANDPAGE_H
