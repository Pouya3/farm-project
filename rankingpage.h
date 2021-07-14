#ifndef RANKINGPAGE_H
#define RANKINGPAGE_H

#include <QMainWindow>

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
};

#endif // RANKINGPAGE_H
