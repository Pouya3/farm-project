#ifndef LEVELUP23_H
#define LEVELUP23_H

#include <QMainWindow>

namespace Ui {
class LevelUp23;
}

class LevelUp23 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelUp23(QWidget *parent = nullptr);
    ~LevelUp23();

private:
    Ui::LevelUp23 *ui;
};

#endif // LEVELUP23_H
