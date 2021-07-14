#ifndef SPACEPAGE_2_H
#define SPACEPAGE_2_H

#include <QMainWindow>

namespace Ui {
class SpacePage_2;
}

class SpacePage_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpacePage_2(QWidget *parent = nullptr);
    ~SpacePage_2();

private:
    Ui::SpacePage_2 *ui;
};

#endif // SPACEPAGE_2_H
