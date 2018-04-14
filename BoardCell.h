#ifndef BOARDCELL_H
#define BOARDCELL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>



#include <iostream>

using namespace std;

class Game;

class BoardCell {

protected:
    int cell_number;

public:
    void setCellNumber(int number);

public:
    //this function only prints the color of Orange Violet and Red cells
    virtual void printColor();
    virtual string getColor();

};
#endif // BOARDCELL_H
