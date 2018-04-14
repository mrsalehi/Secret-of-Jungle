#ifndef REDCELL_H
#define REDCELL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


#include "BoardCell.h"

class RedCell : public BoardCell
{
private:

public:
    virtual void printColor();
    virtual string getColor();
};

#endif // REDCELL_H
