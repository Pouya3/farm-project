#ifndef LEVELUP12_H
#define LEVELUP12_H

#include <QMainWindow>

namespace Ui {
class LevelUp12;
}

class LevelUp12 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelUp12(QWidget *parent = nullptr);
    ~LevelUp12();

private:
    Ui::LevelUp12 *ui;
    QIcon* icon;
    QPixmap* pix;
};

#endif // LEVELUP12_H
