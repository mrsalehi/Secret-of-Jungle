#ifndef BLUECELL_H
#define BLUECELL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


#include "BoardCell.h"

class BlueCell : public BoardCell
{
private:

public:
    virtual string getColor();
};

#endif // BLUECELL_H
