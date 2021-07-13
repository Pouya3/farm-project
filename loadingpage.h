#ifndef LOADINGPAGE_H
#define LOADINGPAGE_H

#include <QMainWindow>

namespace Ui {
class LoadingPage;
}

class LoadingPage : public QMainWindow
{
    Q_OBJECT

public:
    void changing();
    explicit LoadingPage(QWidget *parent = nullptr);
    ~LoadingPage();

private:
    Ui::LoadingPage *ui;
};

#endif // LOADINGPAGE_H
