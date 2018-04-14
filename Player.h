#ifndef PLAYER_H
#define PLAYER_H


#include "BoardCell.h"


class Player
{
private:
    int position;
    int id;

    //stores number of won treasures by a player
    int num_of_won_treasures;

public:
    Player(int position, int id);

    //gets the number of the cell in which the player is
    int getPosition() const;

    void setPosition(int position);

    //gets the input which is given to program by the player
    int getChoice();

    //if a player wins a treasure, this function adds 1 to num_of_won_treasures
    void addNumOfWonTreasures();

    int getNumOfWonTreasures();

    int getId() const;

};

#endif // PLAYER_H
