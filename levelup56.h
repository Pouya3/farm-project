#ifndef LEVELUP56_H
#define LEVELUP56_H

#include <QMainWindow>

namespace Ui {
class LevelUp56;
}

class LevelUp56 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelUp56(QWidget *parent = nullptr);
    ~LevelUp56();

private:
    Ui::LevelUp56 *ui;
};

#endif // LEVELUP56_H
