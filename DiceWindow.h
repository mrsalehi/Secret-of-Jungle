#ifndef DICEWINDOW_H
#define DICEWINDOW_H

#include <QDialog>

namespace Ui {
class DiceWindow;
}

class DiceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DiceWindow(QWidget *parent = 0);
    ~DiceWindow();

    int getFirst_die() const;

    int getSecond_die() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::DiceWindow *ui;
    int first_die;
    int second_die;
};

#endif // DICEWINDOW_H
