#include "SamplePlayer.h"

SamplePlayer::SamplePlayer(int position, int id) : Player(position, id) {}

int SamplePlayer::chooseMove(const vector<int>& accessible_positions, Board &myBoard) {

    //first priority for sample player are red cells
    for (auto i = 0; i < accessible_positions.size(); i++){
        if (myBoard.getColorOfCell(accessible_positions[i]) == "Red"){
            return i + 1;//note that i+1 is the number of choice

        }
    }

    //second priorities are unvisited orange cells
    for (auto i = 0; i < accessible_positions.size(); i++){
        if ( myBoard.getColorOfCell(i) == "Orange"){
            if (!checkVisited(accessible_positions[i]) ) {
                visited_oranges.push_back(accessible_positions[i]);
                orange_cells_treasures[accessible_positions[i]] = myBoard.getNameOfTreasure(accessible_positions[i]);
                return i + 1;
            }
        }
    }

    //third priority are cells in which other players' marbles are
    for (auto i = 0; i < accessible_positions.size(); i++){
        if ( myBoard.getIsFilledCell(accessible_positions[i]) )
            return i + 1;
    }


    return 1;
}

int SamplePlayer::guessTreasure(char goal_treasure) {

    for (auto element : visited_oranges){
        if ( orange_cells_treasures[element] == goal_treasure)
            return element;
    }

    //Sample player prefers not to guess when he doesn't know where the goal treasure is
    //returning 0 means that he doesn't want to guess
    return 0;

}

bool SamplePlayer::checkVisited(int orange_cell_number) {

    for (auto element : visited_oranges)
        if (element == orange_cell_number)
            return true;

    return false;

}

