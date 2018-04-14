#ifndef ASKNUMOFPLAYERS_H
#define ASKNUMOFPLAYERS_H


#include <QDialog>

namespace Ui {
class askNumOfPlayers;
}

class askNumOfPlayers : public QDialog
{
    Q_OBJECT

public:
    explicit askNumOfPlayers(QWidget *parent = 0);
    ~askNumOfPlayers();

    int getNumber_of_players() const;

private slots:
    void on_submit_clicked();

private:
    Ui::askNumOfPlayers *ui;
    int number_of_players;
};

#endif // ASKNUMOFPLAYERS_H
