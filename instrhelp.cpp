#include "instrhelp.h"
#include "ui_instrhelp.h"

instrhelp::instrhelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instrhelp)
{
    ui->setupUi(this);
    ui->explainlabel->setText("At the start of the Game 13 Treasures are distributed among 13 Orange Cells.\nThe players (2,3 or 4) Start from the Blue Cells and attemt to find as much treasures as they\ncan! By Guessing each treasure Correctly the player will get 1 point!");
    ui->prev->hide();
}

instrhelp::~instrhelp()
{
    delete ui;
}

void instrhelp::on_nxt_clicked()
{
    if (ui->titlelabel->text() == "Red Cells")
    {
        hide();
    }
    if (ui->titlelabel->text() == "Orange Cells")
    {
        ui->titlelabel->setText("Red Cells");
        ui->explainlabel->setText("When a player goes to a red cell he/she can guess the treausre! if he doesn't guess he will\nhave the second dice number and can move with it. But if he does , he will see the guessed\ncell's treasures. if the seen treasure was correct , he will win the treasure , get 1 point and\nhave the next turn as well! but if he guesses incorrectly , he will be moved to blue cells and\nthe turn goes to next player!");
        ui->nxt->setText("Finish");
    }
    if (ui->titlelabel->text() == "Same Dices")
    {
        ui->titlelabel->setText("Orange Cells");
        ui->explainlabel->setText("Whenever a player go to Orange Cells , he/she will be able to see the treasure hidden on \nthat cell. but even if he finds the wanted treasure he will not be able to win it before going to\nRed cells!");
    }
    if (ui->titlelabel->text() == "Piece Movement")
    {
        ui->titlelabel->setText("Same Dices");
        ui->explainlabel->setText("If the Player get the dices with the same number , he/she will be able to go to any of the\norange cells or the voilet cell as well as the natural Moves and can also change the goal\ntreasure , The new treasure will be chosen randomly from unfounded treasures.");
    }
    if (ui->titlelabel->text() == "Game Goal")
    {
        ui->prev->show();
        ui->titlelabel->setText("Piece Movement");
        ui->explainlabel->setText("In each turn the player will roll 2 dices and can move twice with those given dice numbers.\nThe movement of 1 dice should be in 1 direction but the movement of the second dice can\ndiffer from the first one!");
    }
}

void instrhelp::on_prev_clicked()
{
    if (ui->titlelabel->text() == "Piece Movement")
    {
        ui->titlelabel->setText("Game Goal");
        ui->explainlabel->setText("At the start of the Game 13 Treasures are distributed among 13 Orange Cells.\nThe players (2,3 or 4) Start from the Blue Cells and attemt to find as much treasures as they\ncan! By Guessing each treasure Correctly the player will get 1 point!");
        ui->prev->hide();
    }

    if (ui->titlelabel->text() == "Same Dices")
    {
        ui->titlelabel->setText("Piece Movement");
        ui->explainlabel->setText("In each turn the player will roll 2 dices and can move twice with those given dice numbers.\nThe movement of 1 dice should be in 1 direction but the movement of the second dice can\ndiffer from the first one!");
    }

    if (ui->titlelabel->text() == "Orange Cells")
    {
        ui->titlelabel->setText("Same Dices");
        ui->explainlabel->setText("If the Player get the dices with the same number , he/she will be able to go to any of the\norange cells or the voilet cell as well as the natural Moves and can also change the goal\ntreasure , The new treasure will be chosen randomly from unfounded treasures.");
    }

    if (ui->titlelabel->text() == "Red Cells")
    {
        ui->titlelabel->setText("Orange Cells");
        ui->nxt->setText("Next");
        ui->explainlabel->setText("Whenever a player go to Orange Cells , he/she will be able to see the treasure hidden on \nthat cell. but even if he finds the wanted treasure he will not be able to win it before going to\nRed cells!");
    }
}
