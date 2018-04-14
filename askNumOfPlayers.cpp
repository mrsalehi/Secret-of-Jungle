#include "askNumOfPlayers.h"
#include "ui_asknumofplayers.h"
#include <QMessageBox>

#include <iostream>


using namespace std;


askNumOfPlayers::askNumOfPlayers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::askNumOfPlayers)
{
    ui->setupUi(this);

}

askNumOfPlayers::~askNumOfPlayers()
{
    delete ui;
}

void askNumOfPlayers::on_submit_clicked()
{


        if (ui->radioButton->isChecked()){
            number_of_players = 2;
            close();
        }
        else if (ui->radioButton_2->isChecked()){
            number_of_players = 3;
            close();
        }
        else if (ui->radioButton_3->isChecked()){
            number_of_players = 4;
            close();
        }
        else
            QMessageBox::warning(this, "Error", "Number of Players isn't identified");


}

int askNumOfPlayers::getNumber_of_players() const
{
    return number_of_players;
}
