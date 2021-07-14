#ifndef RANKINGPAGE_H
#define RANKINGPAGE_H

#include <QMainWindow>
#include <QMultiMap>
#include "user.h"
#include <QTimer>

namespace Ui {
class RankingPage;
}

class RankingPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit RankingPage(User*, QMultiMap<int, QString>, QWidget *parent = nullptr);
    ~RankingPage();

private:
    Ui::RankingPage *ui;
    QMultiMap<int, QString> users_for_ranking;
    User* user;
    QTimer* refresh_timer;

private slots:
    void Set_values();
};

#endif // RANKINGPAGE_H
