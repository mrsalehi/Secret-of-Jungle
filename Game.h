#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "Board.h"
#include "BoardCell.h"
#include "OrangeCell.h"
#include "DicePool.h"
#include "Player.h"



using namespace std;

class Game {
private:
    const int number_of_players;
    char goal_treasure;
    vector<Player*> players;
    bool FirstMoveFirstDie;
    int move_number;
    static int turn;
    static int round;
    vector<char> remaining_treasures;
    static bool isFoundGoalTreasure;
    static bool prizeTurn;
    bool isGuessTreasure;


public:
    static bool isPrizeTurn();
    static void setPrizeTurn(bool prizeTurn);

private:
    Board myBoard;

public:
    Game(const int &number_of_players);

    //sets the treasure at the beginning of the game or when the treasure should be changed
    void setTreasure();

    //declare the goal treasure at the beginning of every round
    char declareGoalTreasure() const;

    //adds one to turn when one's turn is finished
    void nextTurn();

    //make the game go to next round
    void goToNextRound();

    //changes the position of marble of the player who has the turn
    //if a marble is in destination cell, it also sends that marble to blue cells
    void changePosition(const int &cell_number);

    //getters of variables turn and round
    static int getTurn();
    static int getRound();

    //gets the input which is given to the Player class instance by the player who has the turn
    int getInput() const;

    //takes cell number of an orange cell and checks whether it has treasure or not
    bool hasTreasure(const int &cell_number);

    //gets the position of the player who currently has the turn
    int getCurrentPosition() const;

    //gets positions of all of the players
    int* getPositions();

    //contribute the treasures among orange cells at the beginning of the game
    void contributeTreasures();

    //when a player wins the goal treasure, it should be removed from the list of remaining treasures
    //it also adds 1 to number of treasures the player has achieved
    void removeGoalTreasure();

    //getter and setter of static variable isFoundGoalTreasure
    void setIsFoundGoalTreasure(const bool isFoundGoalTreasure);
    bool getIsFoundGoalTreasure();

    int getMoveNumber();

    int getNumOfWonTreasures(int player_id);
    void addNumOfWonTreasures(int player_id);


    //exactly the identical version of following functions exist in Board class

    string getColorOfCell(const int &cell_number);

    const vector<int> &getVioletCellsNumbers() const;

    const vector<int> &getOrangeCellsNumbers() const;

    void printColorOfCell(const int &cell_number);

    char getNameOfTreasure(const int &cell_number);

    bool getIsFilledCell(const int &cell_number);

    void getPossibleMoves(vector<int> &suitable_positions, int current_position, int distance);

    void rollDice();

    int getFirstDieNumber() const;

    int playerInFilledCell(const int &cell_number);

    int getSecondDieNumber() const;

    virtual ~Game();

    void initializeMoveNumber();

    bool getIsGuessTreasure() const;
    void setIsGuessTreasure(bool value);

    void getWinnersId(vector<int>& winners);
};


#endif // GAME_H
