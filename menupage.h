#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QMainWindow>

namespace Ui {
class MenuPage;
}

class MenuPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuPage(QWidget *parent = nullptr);
    ~MenuPage();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::MenuPage *ui;
};

#endif // MENUPAGE_H
