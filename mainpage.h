#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QTimer>
#include "user.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QMessageBox>
#include "storepage.h"
#include "livestockpage.h"
#include "alfalfa_landpage.h"
#include "wheat_landpage.h"
#include "agholpage.h"
#include "marketpage.h"
#include "silopage.h"
#include "aviculturepage.h"

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(User* user, QWidget *parent = nullptr);
    ~MainPage();
public slots:
    void Time_function();
private slots:
    void on_pushButton_a_clicked();

    void on_pushButton_a_8_clicked();

    void on_pushButton_a_5_clicked();

    void on_pushButton_a_6_clicked();

    void on_pushButton_a_7_clicked();

    void on_pushButton_a_4_clicked();

    void on_pushButton_a_3_clicked();

    void on_pushButton_mm_2_clicked();

    void on_pushButton_a_2_clicked();

    void Save_this_user();
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainPage *ui;
    QTimer *timer;
    QTimer *saving_tiemer;
    User * user;
    QIcon* icon;
    QPixmap* pix;
    StorePage* st;
    LivestockPage* li;
    Alfalfa_landPage* al;
    Wheat_landPage* wh;
    SiloPage* si;
    AviculturePage* av;
    AgholPage* ag;
    MarketPage* ma;


};

#endif // MAINPAGE_H
