#ifndef ASKNAMEOFPLAYERS_H
#define ASKNAMEOFPLAYERS_H

#include <QDialog>
#include <iostream>

using namespace std;


namespace Ui {
class AskNameOfPlayers;
}

class AskNameOfPlayers : public QDialog
{
    Q_OBJECT

public:
    explicit AskNameOfPlayers(int num_of_players ,QWidget *parent = 0);
    ~AskNameOfPlayers();

    QString getPlayer1_name() const;

    QString getPlayer2_name() const;

    QString getPlayer3_name() const;

    QString getPlayer4_name() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::AskNameOfPlayers *ui;

    int num_of_players;
    QString player1_name;
    QString player2_name;
    QString player3_name;
    QString player4_name;

};

#endif // ASKNAMEOFPLAYERS_H
