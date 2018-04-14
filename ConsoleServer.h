#ifndef CONSOLESERVER_H
#define CONSOLESERVER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


#include "Game.h"


class ConsoleServer
{
public:


    //main loop of the game is in consoleMain
    void consoleMain();

    //this function helps consoleMain (by printing required messages for Orange or Red cells) to perform a move to
    // a cell by taking that cell's number
    void consoleHelper(Game& myGame, int cell_number);
};

#endif // CONSOLESERVER_H
