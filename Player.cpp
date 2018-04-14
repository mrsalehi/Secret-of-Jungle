#include "Player.h"
#include <iostream>


using namespace std;

int Player::getPosition() const {
    return position;
}

Player::Player(int position, int id) : position(position), id(id){
    num_of_won_treasures = 0;
}

void Player::setPosition(int position) {
    Player::position = position;
}

int Player::getChoice() {
    int choice;
    cin >> choice;
    return choice;
}

int Player::getId() const {
    return id;
}

void Player::addNumOfWonTreasures() {
    num_of_won_treasures++;

}

int Player::getNumOfWonTreasures()
{
    return num_of_won_treasures;

}
