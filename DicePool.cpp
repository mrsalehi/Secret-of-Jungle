#include "DicePool.h"

using namespace std;

void DicePool::rollDice(){
    this->first_die = rand() % 6 + 1;
    this->second_die = rand() % 6 + 1;
}

int DicePool::getFirstDie() const {
    return first_die;
}

int DicePool::getSecondDie() const {
    return second_die;
}
