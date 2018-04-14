#ifndef VIOLETCELL_H
#define VIOLETCELL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


#include "BoardCell.h"
#include <iostream>

using namespace std;

class VioletCell : public BoardCell {

public:
    VioletCell();

private:
    bool isFilled;

public:
    void setIsFilled(bool isFilled);
    bool getIsFilled();

    virtual void printColor();
    virtual string getColor();

};

#endif // VIOLETCELL_H
