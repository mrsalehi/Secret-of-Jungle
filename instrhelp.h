#ifndef INSTRHELP_H
#define INSTRHELP_H

#include <QDialog>

namespace Ui {
class instrhelp;
}

class instrhelp : public QDialog
{
    Q_OBJECT

public:
    explicit instrhelp(QWidget *parent = 0);
    ~instrhelp();

private slots:
    void on_nxt_clicked();

    void on_prev_clicked();

private:
    Ui::instrhelp *ui;
};

#endif // INSTRHELP_H
