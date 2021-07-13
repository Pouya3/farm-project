#ifndef WOOLMARKET_H
#define WOOLMARKET_H

#include <QMainWindow>

namespace Ui {
class WoolMarket;
}

class WoolMarket : public QMainWindow
{
    Q_OBJECT

public:
    explicit WoolMarket(QWidget *parent = nullptr);
    ~WoolMarket();

private:
    Ui::WoolMarket *ui;
};

#endif // WOOLMARKET_H
