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
    explicit LevelUpKoli(int, int, QWidget *parent = nullptr);
    ~LevelUpKoli();

private:
    Ui::LevelUpKoli *ui;
    QIcon* icon;
    QPixmap* pix;
};

#endif // LEVELUPKOLI_H
