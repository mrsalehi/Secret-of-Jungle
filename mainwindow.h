#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <cmath>

#include "askNumOfPlayers.h"
#include "Game.h"
#include "AskNameOfPlayers.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow* getUi();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void buttonClicked();

    void on_roll_dice_clicked();

    void redButtonClicked();

    void EqualDiceButtonsClicked();

    void on_roll_dice_released();

    void on_pushButton_released();

    void on_change_goal_treasure_clicked();

    void on_dont_guess_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton** ptrToChoiceCells;
    QPushButton** ptrToCells;
    Game* myGame;
    QLabel* ptrsToPositionLabel[4];
    QPushButton** ptrToEqualDiceButtons;
    QString player_names[4];
    vector<int> accessible_positions1;
    vector<int> accessible_positions2;
    void changePositionsOnBoard(int src, int dest, int player_number);
    QPushButton* ptrToZeroCells[4];
    QLabel* ptrToScoreLabel[4];

};

#endif // MAINWINDOW_H
