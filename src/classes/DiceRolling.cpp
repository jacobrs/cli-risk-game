#include "../headers/DiceRolling.h"

using namespace std;

DiceRolling::DiceRolling(int numberOfDice){
    number = numberOfDice;
    numberOfRolls = 0;
    dice = new Die*[number];
    for(int i = 0; i < 6; i++){
        valuesRolled[i] = 0;
    }
    total = 0;
    for(int i = 0; i < number ; i++){
        dice[i] = new Die();
    }
}

DiceRolling::DiceRolling(){
    DiceRolling::DiceRolling(1);
}

void DiceRolling::rollDice(){
    for(int i = 0; i < number; i++){
        dice[i]->rollDie();
        total += dice[i]->dieSide;
        numberOfRolls++;
        valuesRolled[dice[i]->dieSide - 1]++;
    }
}
DiceRolling::~DiceRolling(){
    delete[] dice;
}