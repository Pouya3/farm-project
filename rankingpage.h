#ifndef RANKINGPAGE_H
#define RANKINGPAGE_H

#include <QMainWindow>
#include <QMultiMap>
#include "user.h"
#include <QTimer>
#include <vector>


namespace Ui {
class RankingPage;
}

class RankingPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit RankingPage(User*, std::vector<std::pair<int, QString>>, QWidget *parent = nullptr);
    ~RankingPage();

private:
    Ui::RankingPage *ui;
    std::vector<std::pair<int, QString>> users_for_ranking;
    User* user;
    QTimer* refresh_timer;
    QIcon* icon;
    QPixmap* pix;

private slots:
    void Set_values();
};

#endif // RANKINGPAGE_H
