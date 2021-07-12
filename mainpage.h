#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_pushButton_a_clicked();

    void on_pushButton_a_8_clicked();

    void on_pushButton_a_5_clicked();

    void on_pushButton_a_6_clicked();

    void on_pushButton_a_7_clicked();

    void on_pushButton_a_4_clicked();

    void on_pushButton_a_3_clicked();

    void on_pushButton_mm_2_clicked();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
