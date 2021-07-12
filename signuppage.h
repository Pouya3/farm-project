#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QMainWindow>
#include "file_functions.h"

namespace Ui {
class signupPage;
}

class signupPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit signupPage(QWidget *parent = nullptr);
    ~signupPage();

private slots:
    void on_pushButton_s_clicked();

    void on_pushButton_s_2_clicked();

private:
    Ui::signupPage *ui;
};

#endif // SIGNUPPAGE_H
