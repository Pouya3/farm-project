#ifndef LIVESTOCKPAGE_H
#define LIVESTOCKPAGE_H

#include <QMainWindow>

namespace Ui {
class LivestockPage;
}

class LivestockPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit LivestockPage(QWidget *parent = nullptr);
    ~LivestockPage();

private:
    Ui::LivestockPage *ui;
};

#endif // LIVESTOCKPAGE_H
