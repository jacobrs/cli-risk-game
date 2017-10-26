#ifndef DICEROLLING_H
#define DICEROLLING_H

#include "Die.h"

using namespace std;

class DiceRolling{
public:
    //int total;
    //int number;
    //int valuesRolled[6];
    //int numberOfRolls;

    //Die **dice;

    //DiceRolling();
    //DiceRolling(int);
    int* attackAndDefendRoll(int, int);
    //void rollDice();
    void sort(Die**, int);
    ~DiceRolling();
};

#endif
