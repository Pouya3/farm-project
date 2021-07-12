#ifndef AVICULTUREPAGE_H
#define AVICULTUREPAGE_H

#include <QMainWindow>

namespace Ui {
class AviculturePage;
}

class AviculturePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AviculturePage(QWidget *parent = nullptr);
    ~AviculturePage();

private:
    Ui::AviculturePage *ui;
};

#endif // AVICULTUREPAGE_H
