#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QMainWindow>

namespace Ui {
class signupPage;
}

class signupPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit signupPage(QWidget *parent = nullptr);
    ~signupPage();

private:
    Ui::signupPage *ui;
};

#endif // SIGNUPPAGE_H
