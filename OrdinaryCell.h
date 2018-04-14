#ifndef ORDINARYCELL_H
#define ORDINARYCELL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


#include "BoardCell.h"

class OrdinaryCell : public BoardCell
{
    virtual string getColor();

};

#endif // ORDINARYCELL_H
