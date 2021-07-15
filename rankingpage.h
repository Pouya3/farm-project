#ifndef RANKINGPAGE_H
#define RANKINGPAGE_H

#include <QMainWindow>
#include <QMultiMap>
#include "user.h"
#include <QTimer>
#include <vector>
using namespace std;

namespace Ui {
class RankingPage;
}

class RankingPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit RankingPage(User*, vector<pair<int, QString>>, QWidget *parent = nullptr);
    ~RankingPage();

private:
    Ui::RankingPage *ui;
    vector<pair<int, QString>> users_for_ranking;
    User* user;
    QTimer* refresh_timer;

private slots:
    void Set_values();
};

#endif // RANKINGPAGE_H
