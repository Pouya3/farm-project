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

private:
    Ui::MenuPage *ui;
};

#endif // MENUPAGE_H
