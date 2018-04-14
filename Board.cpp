#include "Board.h"


using namespace std;

Board::Board(int v){
    this->v = v;
    adj = new list<int>[v];
    ptrs = new BoardCell *[v + 10];


    int blues[] = {0};
    int oranges[] = {39, 43, 50, 58, 60, 66, 70, 82, 85, 88, 97, 103, 108};
    int reds[] = {25};
    int violets[] = {15};
    int ordinaries[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24,
                         26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 40, 41, 42, 44, 45, 46, 47, 48,
                         49, 51, 52, 53, 54, 55, 56, 57, 59, 61, 62, 63, 64, 65, 67, 68, 69, 71, 72, 73, 74,
                         75, 76, 77, 78, 79, 80, 81, 83, 84, 86, 87, 89, 90, 91, 92, 93, 94, 95, 96, 98, 99,
                         100, 101, 102, 104, 105, 106, 107, 109, 110, 111, 112, 113, 114, 115, 116};


    for (auto element : blues){
        this->blueCellsNumbers.push_back(element);
        blueCells[element].setCellNumber(element);
        ptrs[element] = new BoardCell;
        ptrs[element] = &blueCells[element];
    }

    for (auto element : ordinaries){
        this->ordinaryCellsNumbers.push_back(element);
        ordinaryCells[element].setCellNumber(element);
        ptrs[element] = new BoardCell;
        ptrs[element] = &ordinaryCells[element];
    }
    for (auto element : reds){
        this->redCellsNumbers.push_back(element);
        redCells[element].setCellNumber(element);
        ptrs[element] = new BoardCell;
        ptrs[element] = &redCells[element];
    }
    for (auto element : violets){
        this->violetCellsNumbers.push_back(element);
        violetCells[element].setCellNumber(element);
        ptrs[element] = new BoardCell;
        ptrs[element] = &violetCells[element];
    }
    for (auto element : oranges){
        this->orangeCellsNumbers.push_back(element);
        orangeCells[element].setCellNumber(element);
        ptrs[element] = new BoardCell;
        ptrs[element] = &orangeCells[element];
    }


    for (int i = 0; i < 34; i++)
        addEdge(i, i + 1);

    addEdge(34, 15);
    addEdge(4, 35);

    for (int i = 35; i < 49; i++)
        addEdge(i, i + 1);

    addEdge(48, 50);
    addEdge(49, 37);

    for (int i = 50; i < 53; i++)
        addEdge(i, i + 1);

    addEdge(10, 53);
    addEdge(51, 54);

    for (int i = 54; i < 59; i++)
        addEdge(i, i + 1);

    addEdge(59, 46);

    addEdge(55, 60);

    for (int i = 60; i < 67; i++)
        addEdge(i, i + 1);

    addEdge(57, 67);
    addEdge(63, 68);

    for (int i = 68; i < 78; i++)
        addEdge(i, i + 1);

    addEdge(78, 29);
    addEdge(7, 79);

    for (int i = 79; i < 93; i++)
        addEdge(i, i + 1);

    addEdge(93, 81);
    addEdge(92, 94);

    for (int i = 94; i < 107; i++)
        addEdge(i, i + 1);

    addEdge(107, 95);
    addEdge(106, 108);
    addEdge(108, 109);
    addEdge(109, 11);
    addEdge(101, 110);

    for (int i = 110; i < 116; i++)
        addEdge(i, i + 1);

    addEdge(116, 21);

/*
    //This part is for reading the map from file
    //file vertices.txt contains cells of the game with their colors
    //file edges.txt contains the edges with this format that every line contains one edge (e.g. 1 2 in one line
    // means there's an edge between cells 1 and 2.)

    int x;
    string color;
    ifstream infile;
    infile.open("vertices.txt");

    while(!infile.eof()) {

        infile >> x;
        infile >> color;

       if (color == "Red"){

           redCellsNumbers.push_back(x);
           redCells[x].setCellNumber(x);
           ptrs[x] = new BoardCell;
           ptrs[x] = &redCells[x];

       } else if (color == "Orange"){

           orangeCellsNumbers.push_back(x);
           orangeCells[x].setCellNumber(x);
           ptrs[x] = new BoardCell;
           ptrs[x] = &orangeCells[x];

       } else if (color == "Green"){

           ordinaryCellsNumbers.push_back(x);
           ordinaryCells[x].setCellNumber(x);
           ptrs[x] = new BoardCell;
           ptrs[x] = &ordinaryCells[x];

       } else if (color == "Violet"){

           violetCellsNumbers.push_back(x);
           violetCells[x].setCellNumber(x);
           ptrs[x] = new BoardCell;
           ptrs[x] = &violetCells[x];

       } else if (color == "Blue"){

           blueCellsNumbers.push_back(x);
           blueCells[x].setCellNumber(x);
           ptrs[x] = new BoardCell;
           ptrs[x] = &blueCells[x];
       }

    }
    infile.close();


    infile.open("edges.txt");

    int y;
    while(!infile.eof()){

        infile >> x;
        infile >> y;
        addEdge(x, y);
    }

    infile.close();

*/

}

void Board::getPossibleMoves(vector<int> &suitable_positions, int s, int distance) {

    int** paths = new int* [1000];
    int* sizes = new int[1000];

    for (int i = 0; i < 1000; i++) {
        paths[i] = new int[6];
    }



    paths[0][0] = s;
    sizes[0] = 1;

    int first = 0, last = 0;
    int new_last;

    int my_distance = 1;
    while ( my_distance <= distance){


        new_last = last;

        for (int i = first; i <= last; i++)
        {
            for ( auto element : adj[paths[i][sizes[i] - 1]] ){
                if ( !isVisited( paths[i], sizes[i], element ) ){
                    new_last++;
                    makeNewPath(paths, i, new_last, sizes[i], element);
                    sizes[new_last] = sizes[i] + 1;
                }

            }

        }

        first = last + 1;
        last = new_last;

        my_distance++;
    }

    for (int i = first; i <= last; i++){

        int v = paths[i][sizes[i] - 1];
        if (v != 0)
            suitable_positions.push_back( paths[i][sizes[i] - 1] );
    }




}

void Board::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

const vector<int> &Board::getOrangeCellsNumbers() const {
    return orangeCellsNumbers;
}

const vector<int> &Board::getVioletCellsNumbers() const {
    return violetCellsNumbers;
}

string Board::getColorOfCell(const int &cell_number) {
    return ptrs[cell_number]->getColor();
}

void Board::printColorOfCell(const int &cell_number) {
    ptrs[cell_number]->printColor();
}

char Board::getNameOfTreasure(const int &cell_number) {
    return dynamic_cast<OrangeCell *>(ptrs[cell_number])->getTreasureName();
}

void Board::setNameOfTreasure(const char &treasure_name, const int &cell_number) {
    dynamic_cast<OrangeCell *>(ptrs[cell_number])->setTreasureName(treasure_name);

}

bool Board::getIsFilledCell(const int &cell_number) {

    if (dynamic_cast<OrangeCell*>(ptrs[cell_number]))
        return dynamic_cast<OrangeCell*>(ptrs[cell_number])->getIsFilled();
    else
        return dynamic_cast<VioletCell*>(ptrs[cell_number])->getIsFilled();
}

void Board::setIsFilledCell(const int &cell_number, const bool isFilled) {

    if (dynamic_cast<OrangeCell*>(ptrs[cell_number]))
        dynamic_cast<OrangeCell*>(ptrs[cell_number])->setIsFilled(isFilled);
    else
        dynamic_cast<VioletCell*>(ptrs[cell_number])->setIsFilled(isFilled);
}

int Board::getFirstDieNumber() const{
    return myDice.getFirstDie();
}

int Board::getSecondDieNumber() const{
    return  myDice.getSecondDie();
}

void Board::rollDice() {

    myDice.rollDice();

}

Board::~Board() {
}

bool Board::isVisited(int *path, int size, int new_vertex) {

    for (int i = 0; i < size; i++){
        if (path[i] == new_vertex)
            return true;
    }

    return false;

}

void Board::makeNewPath(int **paths, int path_number, int new_path_number, int size, int new_vertex) {

    for (int i = 0; i < size; i++){
        paths[new_path_number][i] = paths[path_number][i];
    }
    paths[new_path_number][size] = new_vertex;

}

