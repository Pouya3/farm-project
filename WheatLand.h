#ifndef WHEATLAND_H
#define WHEATLAND_H

#include <QWidget>

namespace Ui {
class WheatLand;
}

class WheatLand : public QWidget
{
    Q_OBJECT

public:
    explicit WheatLand(QWidget *parent = nullptr);
    ~WheatLand();

private:
    Ui::WheatLand *ui;
};

#endif // WHEATLAND_H
