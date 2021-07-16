#ifndef LEVELUP45_H
#define LEVELUP45_H

#include <QMainWindow>

namespace Ui {
class LevelUp45;
}

class LevelUp45 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelUp45(QWidget *parent = nullptr);
    ~LevelUp45();

private:
    Ui::LevelUp45 *ui;
    QIcon* icon;
    QPixmap* pix;
};

#endif // LEVELUP45_H
