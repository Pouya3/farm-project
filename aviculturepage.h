#ifndef AVICULTUREPAGE_H
#define AVICULTUREPAGE_H

#include <QMainWindow>
#include "aviculture.h"
#include <QTimer>

namespace Ui {
class AviculturePage;
}

class AviculturePage : public QMainWindow
{
    Q_OBJECT
private:
    Aviculture* aviculture;
public:
    explicit AviculturePage(Aviculture*, QWidget *parent = nullptr);
    ~AviculturePage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void Set_values();

private:
    Ui::AviculturePage *ui;
    QTimer* refresh_timer;
};

#endif // AVICULTUREPAGE_H
