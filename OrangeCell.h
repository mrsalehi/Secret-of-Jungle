#ifndef ORANGECELL_H
#define ORANGECELL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


#include "BoardCell.h"

#include <iostream>

using namespace std;

class OrangeCell : public BoardCell
{
private:
public:
    OrangeCell();

private:
    char treasure_name;
    bool isFilled;
public:


    //when a player probably, can reach an orange cell, the color of the cell (Orange) should be printed in the choice
    virtual void printColor();


    virtual string getColor();

    void setIsFilled(bool isFilled);

    bool getIsFilled();

    char getTreasureName();

    //sets the treasure of every orange cell at the beginning of the game
    void setTreasureName(char treasure_name);
};

#endif // ORANGECELL_H
