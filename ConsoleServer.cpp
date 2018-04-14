#include "ConsoleServer.h"

#include <iostream>


using namespace std;


void ConsoleServer::consoleMain() {


    srand((time(NULL)));//seeding the pseudo-random number used in DicePool & set treasure

    int num_of_players;
    cout << "How many players are going to play?" << endl;


    //cin >> num_of_players;

    num_of_players = 3;

    int first_die, second_die;


    Game myGame(num_of_players);//making an instance of the Game class
    myGame.contributeTreasures();//contribute treasures among orange cells randomly


    myGame.setTreasure();//define the goal treasure of current round
    cout << "Round number " << myGame.getRound() << " started, this round's goal treasure is "
         << myGame.declareGoalTreasure() << endl;


//    ifstream infile;
//    infile.open("Dice.txt");


    //The main loop of the game!
    while( myGame.getRound() <= myGame.getOrangeCellsNumbers().size() ) {

        /*when we get out of console Helper scope, if the goal treasure has been found by a player,
          isFoundGoalTreasure becomes true. at the beginning of every round it becomes false. */
        myGame.setIsFoundGoalTreasure(false);


        int cell_number;
        cell_number = myGame.getCurrentPosition();
        //following if is for checking the prize turn
        if ( myGame.getColorOfCell(cell_number) == "Red" && myGame.isPrizeTurn() ){

            consoleHelper( myGame, cell_number );

            if ( myGame.getIsFoundGoalTreasure() ) {

                myGame.setIsFoundGoalTreasure(false);
                if ( myGame.getRound() <= myGame.getOrangeCellsNumbers().size() ) {
                    continue;
                }
                else {
                    break;
                }

            } else if ( myGame.getCurrentPosition() == 0 ) {
                myGame.setPrizeTurn(false);
                myGame.nextTurn();
                continue;
            }
        }
        myGame.setPrizeTurn(false);


        //producing dice numbers
        myGame.rollDice();
        first_die = myGame.getFirstDieNumber();
        second_die = myGame.getSecondDieNumber();

//        cout << "Dice Numbers: ";
//        cin >> first_die >> second_die;


//        if ( !infile.eof() ) {
//            infile >> first_die;
//            infile >> second_die;
//        }


        //declare the situation of the game at the beginning of every round
        int *positions = new int [num_of_players];
        positions = myGame.getPositions();
        cout << "Current Positions: ";
        for (int l = 0; l < num_of_players; l++)
            cout << l + 1 << "->" << positions[l] << " ";

        cout << endl;
        delete[] positions;
        //
        cout << "Dice Numbers for Player " << Game::getTurn() + 1 << ": " << first_die << " " << second_die << endl;




        //finding accessible positions for the first move (first die), and copying them into accessible_positions1
        vector<int> accessible_positions1;
        myGame.getPossibleMoves(accessible_positions1, myGame.getCurrentPosition(), first_die);

        int enumerator = 1;//just for enumeration of choices

        cout << "Player " << myGame.getTurn() + 1 << "'s Choices:" << endl;
        for ( auto element : accessible_positions1 ) {
            cout << enumerator << ". " << "Move to " << element;
            myGame.printColorOfCell(element);//for printing the color of the cell if it is Orange, Red or Violet
            cout << ", and then move " << second_die << " cells" << endl;
            enumerator++;
        }

        //enumerator1 and enumerator2, like enumerator, are just for enumerations of choices and nothing else
        int enumerator1 = enumerator;
        int enumerator2 = 0;


        //Following vectors are useful when dice numbers are equal and a player wants go to FREE orange or violet cells
        vector<int> freeOrangeCells, freeVioletCells;


        //finding the accessible positions for the first move (second die) provided that dice numbers are different
        //accessible positions are copied to following vector
        vector<int> accessible_positions2;
        myGame.getPossibleMoves( accessible_positions2, myGame.getCurrentPosition(), second_die );

        if ( first_die != second_die ) {
            for ( auto element : accessible_positions2 ) {
                cout << enumerator1 << ". " << "Move to " << element;
                myGame.printColorOfCell(element);//for printing the color of the cell if it is Orange, Red or Violet
                cout << ", and then move " << first_die << " cells" << endl;
                enumerator1++;
            }
        } else { //in case of equal dice numbers, we have three more kinds of choices (going to Orange Cells,
            // Violet Cells or changing the goal treasure)

            //note that we can only move to free Orange and Violet cells in case of equal dice numbers
            //following fors are for finding free Orange & Violet cells
            for ( auto orange_cell_number : myGame.getOrangeCellsNumbers() ){
                if (!myGame.getIsFilledCell(orange_cell_number))
                    freeOrangeCells.push_back(orange_cell_number);
            }
            for ( auto violet_cell_number : myGame.getVioletCellsNumbers() ){
                if (!myGame.getIsFilledCell(violet_cell_number))
                    freeVioletCells.push_back(violet_cell_number);
            }


            for ( auto element : freeOrangeCells ) {
                cout << enumerator1 << ". Move to " << element << "(Orange)" << endl;
                enumerator1++;
            }

            enumerator2 = enumerator1;
            for ( auto element : freeVioletCells ) {
                cout << enumerator2 << ". Move to " << element << "(Violet)" << endl;
                enumerator2++;
            }
            cout << enumerator2 << ". Change current round's goal treasure" << endl;//The last choice

        }



        //getting the input for the first move (note that myGame.getInput() gets input from player who has the turn)
        int choice = myGame.getInput();

        if (choice < enumerator) {//means that first move is with the first die's number

            cell_number = accessible_positions1[choice - 1];
            myGame.changePosition(cell_number);//performing first move
            consoleHelper(myGame, cell_number);//printing required messages after the move (for Orange & Red cells)


            /*following if is for checking whether the guess of the player is right or not
              if it's right and the game is not finished, we use continue to go to next
              while loop with the prize turn for current player in the next round.
              if it's not right we should go to next round without prize turn
              (second move is not allowed! so we use continue)*/
            if ( myGame.getColorOfCell(cell_number) == "Red" ) {
                if (myGame.getIsFoundGoalTreasure()) {
                    myGame.setIsFoundGoalTreasure(false);

                    //following if is for checking whether the game should be finished or not
                    if ( myGame.getRound() <= myGame.getOrangeCellsNumbers().size() )
                        continue;
                    else {
                        break;
                    }
                } else if (myGame.getCurrentPosition() == 0) {
                    //means that the player's guess was wrong since he is in blue cells so it is next player's turn
                    //second move is not allowed also
                    myGame.nextTurn();
                    continue;
                }

            }

            int enumerator3 = 1;
            vector<int> final_positions;
            myGame.getPossibleMoves(final_positions, accessible_positions1[choice - 1], second_die);
            cout << "Player " << myGame.getTurn() + 1 << "'s Choices(Second Dice):" << endl;
            for (auto element : final_positions) {
                cout << enumerator3 << ". " << "Move to " << element;
                myGame.printColorOfCell(element);//for printing the color of the cell if it is Orange, Red or Violet
                cout << endl;
                enumerator3++;
            }
            choice = myGame.getInput();//gets input for the second move
            cell_number = final_positions[choice - 1];

        } else if (first_die != second_die) {

            vector<int> final_positions;
            cell_number = accessible_positions2[choice - enumerator];
            myGame.changePosition(cell_number);//first move
            consoleHelper(myGame, cell_number);

            if (myGame.getColorOfCell(cell_number) == "Red") {
                if (myGame.getIsFoundGoalTreasure()) {
                    myGame.setIsFoundGoalTreasure(false);
                    if (myGame.getRound() <= myGame.getOrangeCellsNumbers().size())
                        continue;
                    else
                        break;
                } else if (myGame.getCurrentPosition() == 0) {
                    myGame.nextTurn();
                    continue;
                }
            }

            int enumerator3 = 1;
            cout << "Player " << myGame.getTurn() + 1 << "'s Choices(Second Dice):" << endl;
            myGame.getPossibleMoves(final_positions, accessible_positions2[choice - enumerator], first_die);
            for (auto element : final_positions) {
                cout << enumerator3 << ". " << "Move to " << element;
                myGame.printColorOfCell(element);//for printing the color of the cell if it is Orange, Red or Violet
                cout << endl;
                enumerator3++;
            }
            choice = myGame.getInput();//get the input for second move
            cell_number = final_positions[choice - 1];

        } else {//means that dice numbers are equal
            if (choice < enumerator1) {//means that the marble should be moved to an Orange cell
                cell_number = freeOrangeCells[choice - enumerator];

            } else if (choice < enumerator2) {//means that the marble should be moved to a Violet cell
                cell_number = freeVioletCells[choice - enumerator1];

            } else{//means that we should change the goal treasure

                myGame.setTreasure();//change the goal treasure
                cout << "Round number " << myGame.getRound() << ", this round's goal treasure has changed to "
                     << myGame.declareGoalTreasure() << endl;

            }

        }


        //if choice = enumerator2, it means that the player just changed the goal treasure and there is no need to move
        //so we don't call change position and console Helper functions
        if (choice != enumerator2) {
            myGame.changePosition(cell_number);//second move
            consoleHelper(myGame, cell_number);
            if (myGame.getColorOfCell(cell_number) == "Red") {
                if (myGame.getIsFoundGoalTreasure()) {
                    myGame.setIsFoundGoalTreasure(false);
                    if (myGame.getRound() <= myGame.getOrangeCellsNumbers().size())
                        continue;
                    else
                        break;
                } else if (myGame.getCurrentPosition() == 0) {
                    myGame.nextTurn();
                    continue;
                }
            }
        }

        myGame.nextTurn();



    }

//    infile.close();

}

void ConsoleServer::consoleHelper (Game& myGame, int cell_number) {

    if (myGame.getColorOfCell(cell_number) == "Orange") {
        cout << "Cell " << cell_number << "'s treasure as seen by player " << myGame.getTurn() + 1
             << " is " << myGame.getNameOfTreasure(cell_number) << endl;

    }
    else if (myGame.getColorOfCell(cell_number) == "Red") {



        cout << "Player " << myGame.getTurn() + 1 << " is in " << cell_number
             << "(Red), and can attempt to guess goal treasure's place:" << endl;

        cout << "1. I don't want to guess" << endl;

        int k = 2;//just for enumeration of choices
        for (int i = 0; i < myGame.getOrangeCellsNumbers().size(); i++) {
            cout << k << ". It's " << myGame.getOrangeCellsNumbers()[i] << endl;
            k++;
        }

        int choice;
        choice = myGame.getInput();
        int cell_number1 = myGame.getOrangeCellsNumbers()[choice - 2];

        if (choice > 1) {
            cout << "Cell " << cell_number1 << "'s treasure as seen by player " << myGame.getTurn() + 1
                 << " is "  << myGame.getNameOfTreasure(cell_number1) << endl;


            if (myGame.hasTreasure(cell_number1)) {
                cout << "Player " << myGame.getTurn() + 1 << "'s guess, " << cell_number1
                     << ", was correct and he/she has won this round's goal treasure, "
                     << myGame.declareGoalTreasure() << endl;
                myGame.removeGoalTreasure();//remove the goal treasure since it's achieved by someone
                myGame.goToNextRound();//goal treasure is achieved by a player so next round should be started

                if (myGame.getRound() <= myGame.getOrangeCellsNumbers().size()){
                    myGame.setTreasure();//setting the treasure of the next round

                    cout << "Round number " << myGame.getRound() << " started, this round's goal treasure is "
                         << myGame.declareGoalTreasure() << endl;
                }

                myGame.setIsFoundGoalTreasure(true);
                myGame.setPrizeTurn(true);


            } else {
                cout << "Player " << myGame.getTurn() + 1 << "'s guess, " << cell_number1 << ", was not correct"
                     << endl << "Player " << myGame.getTurn() + 1 << " is moved to Blue cells" << endl;
                myGame.changePosition(0);
            }
        }

    }
}

