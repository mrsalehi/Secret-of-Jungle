#ifndef SAMPLEPLAYER_H
#define SAMPLEPLAYER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "Player.h"
#include "Board.h"

#include <iostream>
#include <vector>
#include <Map>

using namespace std;

class SamplePlayer : public Player
{
private:
    vector<int> visited_oranges;
    map<int, char> orange_cells_treasures;

public:
    SamplePlayer(int position, int id);
    int chooseMove(const vector<int>& accessible_positions, Board &myBoard);
    int guessTreasure(char goal_treasure);

private:
    bool checkVisited(int orange_cell_number);


};

#endif // SAMPLEPLAYER_H
