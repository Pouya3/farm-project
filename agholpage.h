#ifndef AGHOLPAGE_H
#define AGHOLPAGE_H

#include <QMainWindow>

namespace Ui {
class AgholPage;
}

class AgholPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AgholPage(QWidget *parent = nullptr);
    ~AgholPage();

private:
    Ui::AgholPage *ui;
};

#endif // AGHOLPAGE_H
