#include "Game.h"

int Game::turn = 0;
int Game::round = 1;
bool Game::prizeTurn = false;
bool Game::isFoundGoalTreasure = false;

Game::Game(const int &number_of_players) : number_of_players(number_of_players), myBoard(200){

    Player** my_players = new Player*[number_of_players];


    for (int i = 0; i < number_of_players; i++)
    {
        my_players[i] = new Player(0, i);
        players.push_back(my_players[i]);
    }

    for (int i = 0; i < myBoard.getOrangeCellsNumbers().size(); i++){
        remaining_treasures.push_back(static_cast<char>(i + 65));
    }

    move_number = 1;
    isGuessTreasure = false;
}

char Game::declareGoalTreasure() const {
    return goal_treasure;
}

void Game::nextTurn() {
    Game::turn++;
    Game::turn %= number_of_players;
}

int Game::getTurn() {
    return turn;
}

int Game::getInput() const {
    return players[Game::turn]->getChoice();

}

void Game::changePosition(const int& cell_number) {

    string color = myBoard.getColorOfCell(getCurrentPosition());

    if (color == "Orange" || color == "Violet")
        myBoard.setIsFilledCell(getCurrentPosition(), false);

    if (cell_number != 0) {
        for (auto element : players)
            if (element->getPosition() == cell_number) {
                element->setPosition(0);
            }
    }

    color = myBoard.getColorOfCell(cell_number);
    if (color == "Orange" || color == "Violet")
        myBoard.setIsFilledCell(cell_number, true);

    players[Game::turn]->setPosition(cell_number);

    move_number = (move_number % 2) + 1;


}

void Game::setTreasure() {

    bool isFound = false;
    char tmp;
    while(!isFound){
        tmp = static_cast<char>(rand() % 13 + 65);

        for (auto element : remaining_treasures)
            if (tmp == element)
                isFound = true;
    }
    goal_treasure = tmp;
}

int Game::getCurrentPosition() const{
    return players[Game::turn]->getPosition();
}

bool Game::hasTreasure(const int &cell_number) {
    if (myBoard.getNameOfTreasure(cell_number) == goal_treasure)
        return true;
    else
        return false;
}

void Game::contributeTreasures() {

    bool* chosen = new bool[remaining_treasures.size()];
    for (int i = 0; i < remaining_treasures.size(); i++)
        chosen[i] = false;

    bool isFound;
    for (int i = 0; i < remaining_treasures.size(); i++){

        isFound = false;
        int index = 0;
        while(!isFound){
            index = rand() % static_cast<int>(remaining_treasures.size());

            if (!chosen[index]){
                isFound = true;
                chosen[index] = true;
            }
        }
        char tmp = static_cast<char>(index + 65);
        myBoard.setNameOfTreasure(tmp, myBoard.getOrangeCellsNumbers()[i]);

    }
    delete []chosen;
}

void Game::removeGoalTreasure() {

    vector<char> tmp;

    for (auto element : remaining_treasures)
        if (element != goal_treasure)
            tmp.push_back(element);

    remaining_treasures.clear();

    for (auto element : tmp)
        remaining_treasures.push_back(element);

}

int Game::getRound() {
    return round;
}

void Game::goToNextRound() {
    round++;
}

void Game::setIsFoundGoalTreasure(const bool isFoundGoalTreasure) {
    Game::isFoundGoalTreasure = isFoundGoalTreasure;
}

bool Game::getIsFoundGoalTreasure(){
    return isFoundGoalTreasure;
}

int Game::getMoveNumber()
{
    return move_number;
}

int Game::getNumOfWonTreasures(int player_id)
{
    return players[player_id]->getNumOfWonTreasures();
}

void Game::addNumOfWonTreasures(int player_id)
{
    players[player_id]->addNumOfWonTreasures();
};

bool Game::getIsGuessTreasure() const
{
    return isGuessTreasure;
}

void Game::setIsGuessTreasure(bool value)
{
    isGuessTreasure = value;
}

void Game::getWinnersId(vector<int>& winners)
{
    int max = -1;
    for (auto player : players){

        if (player->getNumOfWonTreasures() > max){
            max = player->getNumOfWonTreasures();
            winners.clear();
            winners.push_back(player->getId());
        }else if(player->getNumOfWonTreasures() == max) {
            winners.push_back(player->getId());
        }
    }


}

bool Game::isPrizeTurn() {
    return prizeTurn;
}

void Game::setPrizeTurn(const bool prizeTurn) {
    Game::prizeTurn = prizeTurn;
}

int *Game::getPositions() {
    int* positions = new int[number_of_players];

    for (int i =0 ; i < number_of_players; i++)
        positions[i] = players[i]->getPosition();

    return positions;
}

string Game::getColorOfCell(const int &cell_number) {
    return myBoard.getColorOfCell(cell_number);
}

void Game::printColorOfCell(const int &cell_number) {
    myBoard.printColorOfCell(cell_number);
}

char Game::getNameOfTreasure(const int &cell_number) {
    return myBoard.getNameOfTreasure(cell_number);
}

const vector<int> &Game::getVioletCellsNumbers() const {
    return myBoard.getVioletCellsNumbers();
}

const vector<int> &Game::getOrangeCellsNumbers() const {
    return myBoard.getOrangeCellsNumbers();
}

void Game::getPossibleMoves(vector<int> &suitable_positions, int current_position, int distance) {
    myBoard.getPossibleMoves(suitable_positions, current_position, distance);
}

bool Game::getIsFilledCell(const int &cell_number) {
    return myBoard.getIsFilledCell(cell_number);
}

int Game::playerInFilledCell(const int &cell_number){

    for (auto element : players){
        if (element->getPosition() == cell_number)
            return element->getId();
    }

    return -1;


}

int Game::getFirstDieNumber() const{
    return myBoard.getFirstDieNumber();
}

int Game::getSecondDieNumber() const{
    return  myBoard.getSecondDieNumber();
}

void Game::rollDice() {

    myBoard.rollDice();

}

Game::~Game() {

}

void Game::initializeMoveNumber()
{
    move_number = 1;

}

