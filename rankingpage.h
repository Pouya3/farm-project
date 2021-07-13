#ifndef RANKINGPAGE_H
#define RANKINGPAGE_H

#include <QMainWindow>
#include <QMultiMap>
#include "user.h"

namespace Ui {
class RankingPage;
}

class RankingPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit RankingPage(QWidget *parent = nullptr);
    ~RankingPage();

private:
    Ui::RankingPage *ui;
    QMultiMap<int, QString> users_for_ranking;
    User* user;
};

#endif // RANKINGPAGE_H
