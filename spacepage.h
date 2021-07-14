#ifndef SPACEPAGE_H
#define SPACEPAGE_H

#include <QMainWindow>

namespace Ui {
class SpacePage;
}

class SpacePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit SpacePage(QWidget *parent = nullptr);
    ~SpacePage();

private:
    Ui::SpacePage *ui;
};

#endif // SPACEPAGE_H
