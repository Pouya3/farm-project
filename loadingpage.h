#ifndef LOADINGPAGE_H
#define LOADINGPAGE_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class LoadingPage;
}

class LoadingPage : public QMainWindow
{
    Q_OBJECT

public:
    void changing();
    explicit LoadingPage(User*, QWidget *parent = nullptr);
    ~LoadingPage();

private:
    Ui::LoadingPage *ui;
    User* user;
    QTimer* timer;
    QIcon* icon;
    QPixmap* pix;

private slots:
    void close_this();
};

#endif // LOADINGPAGE_H
