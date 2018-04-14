#ifndef DICEPOOL_H
#define DICEPOOL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>



#include <cstdlib>

class DicePool {
private:
    int first_die;
    int second_die;
public:

    int getFirstDie() const;
    int getSecondDie() const;
    void rollDice();
};

#endif // DICEPOOL_H
