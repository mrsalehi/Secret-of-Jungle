#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


#include "BoardCell.h"
#include "OrangeCell.h"
#include "RedCell.h"
#include "BlueCell.h"
#include "OrdinaryCell.h"
#include "VioletCell.h"
#include "DicePool.h"

#include <iostream>
#include <list>
#include <vector>
#include <fstream>

using namespace std;


class Board {

private:
    int v;
    list<int>* adj;
    BoardCell** ptrs;

    //following vectors contain the NUMBERS of cells
    vector<int> orangeCellsNumbers;
    vector<int> redCellsNumbers;
    vector<int> ordinaryCellsNumbers;
    vector<int> violetCellsNumbers;
    vector<int> blueCellsNumbers;

    //following arrays contain the cells themselves
    OrdinaryCell ordinaryCells[200];
    VioletCell violetCells[120];
    OrangeCell orangeCells[120];
    BlueCell blueCells[120];
    RedCell redCells[120];

    DicePool myDice;

private:
    void addEdge(int v, int w);

    //a function which helps th getPossibleMoves to find the vertexes that have a specific distance from a
    // specific vertex
    bool isVisited(int *path, int size, int new_vertex);

    //a functions that helps getPossibleMoves to make all paths starting from an specific vertex
    void makeNewPath(int** paths, int path_number, int number_of_paths,  int size, int new_vertex);

public:

    Board(int v);

    const vector<int> &getOrangeCellsNumbers() const;

    const vector<int> &getVioletCellsNumbers() const;

    //takes Board cell number and finds all of the cells which has a path to that cell with length of distance
    void getPossibleMoves(vector<int> &suitable_positions, int current_position, int distance);

    string getColorOfCell(const int &cell_number);

    void printColorOfCell(const int &cell_number);

    //takes number of an orange cell and gives the name of the treasure which is in that cell
    char getNameOfTreasure(const int &cell_number);

    //sets treasures of orange cells at the beginning of the game
    void setNameOfTreasure(const char &treasure_name, const int &cell_number);

    //returns a boolean which shows that a specific cell is filled with any marbles or not
    bool getIsFilledCell(const int &cell_number);


    void setIsFilledCell(const int &cell_number, const bool isFilled);


    int getFirstDieNumber() const;
    int getSecondDieNumber() const;

    void rollDice();

    virtual ~Board();

};


#endif // BOARD_H
