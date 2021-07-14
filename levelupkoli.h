#ifndef LEVELUPKOLI_H
#define LEVELUPKOLI_H

#include <QMainWindow>

namespace Ui {
class LevelUpKoli;
}

class LevelUpKoli : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelUpKoli(QWidget *parent = nullptr);
    ~LevelUpKoli();

private:
    Ui::LevelUpKoli *ui;
};

#endif // LEVELUPKOLI_H
