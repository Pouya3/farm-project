#ifndef SILOPAGE_H
#define SILOPAGE_H

#include <QMainWindow>

namespace Ui {
class SiloPage;
}

class SiloPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit SiloPage(QWidget *parent = nullptr);
    ~SiloPage();

private:
    Ui::SiloPage *ui;
};

#endif // SILOPAGE_H
