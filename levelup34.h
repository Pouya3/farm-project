#ifndef LEVELUP34_H
#define LEVELUP34_H

#include <QMainWindow>

namespace Ui {
class LevelUp34;
}

class LevelUp34 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelUp34(QWidget *parent = nullptr);
    ~LevelUp34();

private:
    Ui::LevelUp34 *ui;
};

#endif // LEVELUP34_H
