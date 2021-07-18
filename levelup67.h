#ifndef LEVELUP67_H
#define LEVELUP67_H

#include <QMainWindow>

namespace Ui {
class LevelUp67;
}

class LevelUp67 : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelUp67(QWidget *parent = nullptr);
    ~LevelUp67();

private:
    Ui::LevelUp67 *ui;
    QIcon* icon;
    QPixmap* pix;
};

#endif // LEVELUP67_H
