#ifndef WOOLPAGE_H
#define WOOLPAGE_H

#include <QMainWindow>

namespace Ui {
class WoolPage;
}

class WoolPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit WoolPage(QWidget *parent = nullptr);
    ~WoolPage();

private:
    Ui::WoolPage *ui;
};

#endif // WOOLPAGE_H
