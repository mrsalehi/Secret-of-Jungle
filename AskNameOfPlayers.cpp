#include "AskNameOfPlayers.h"
#include "ui_AskNameOfPlayers.h"

AskNameOfPlayers::AskNameOfPlayers(int num_of_players, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AskNameOfPlayers)
{
    this->num_of_players = num_of_players;
    ui->setupUi(this);
    if (num_of_players == 2){
        ui->lineEdit_3->hide();
        ui->lineEdit_4->hide();
    } else if (num_of_players == 3){
        ui->lineEdit_4->hide();
    }
    ui->exceptionlbl->hide();
}

AskNameOfPlayers::~AskNameOfPlayers()
{
    delete ui;
}

void AskNameOfPlayers::on_pushButton_clicked()
{
    try
    {
        player1_name = ui->lineEdit->text();
        player2_name = ui->lineEdit_2->text();
        if (player1_name == "" || player2_name == "")
        {
            throw string ("Some Fields aren't Filled!");
        }
        if (num_of_players >= 3)
        {
            player3_name = ui->lineEdit_3->text();
            if (player3_name == "")
            {
                throw string ("Some Fields aren't Filled!");
            }
        }
        if (num_of_players == 4)
        {
            player4_name = ui->lineEdit_4->text();
            if (player4_name == "")
            {
                throw string ("Some Fields aren't Filled!");
            }
        }



        close();
    }

    catch (string &s)
    {
        ui->exceptionlbl->setText("Some Fields aren't filled.");
        ui->exceptionlbl->show();
    }

}

QString AskNameOfPlayers::getPlayer4_name() const
{
    return player4_name;
}

QString AskNameOfPlayers::getPlayer3_name() const
{
    return player3_name;
}

QString AskNameOfPlayers::getPlayer2_name() const
{
    return player2_name;
}

QString AskNameOfPlayers::getPlayer1_name() const
{
    return player1_name;
}
