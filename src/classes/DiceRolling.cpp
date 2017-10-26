#include "../headers/DiceRolling.h"

#include<iostream>
using namespace std;

int* DiceRolling::attackAndDefendRoll(int attackNbOfDices, int defendNbOfDices){ // returns number of armies lost during that turn {attackerArmyLoss, defenderArmyLoss}
  Die** attackDices = new Die*[attackNbOfDices];
  for(int att = 0; att < attackNbOfDices; att++){
    attackDices[att] = new Die();
    attackDices[att]->rollDie();
  }
  Die** defendDices = new Die*[defendNbOfDices];
  for(int def = 0; def < defendNbOfDices; def++){
    defendDices[def] = new Die();
    defendDices[def]->rollDie();
  }

  sort(attackDices, attackNbOfDices);
  sort(defendDices, defendNbOfDices);

  cout << "Attacking country rolls: ";
  for(int att = 0; att < attackNbOfDices; att++){
    cout << attackDices[att]->dieSide;
  }
  cout << endl;

  cout << "Defending country rolls: ";
  for(int def = 0; def < defendNbOfDices; def++){
    cout << defendDices[def]->dieSide;
  }

  int dicesToCompare = (attackNbOfDices >= defendNbOfDices) ? defendNbOfDices : attackNbOfDices; // compare the least amount of dices
  int* casualties = new int[2]{0,0};

  cout << endl << "compare " << dicesToCompare << endl;
  for(int d = 0; d < dicesToCompare; d++){
    if(attackDices[d]->dieSide <= defendDices[d]->dieSide){
      casualties[0]++; // attacker loses one army
    }
    else{
      casualties[1]++; // defender loses one army
    }
  }

  for(int a = 0; a < attackNbOfDices; a++){
    delete attackDices[a];
  }
  for(int d = 0; d < defendNbOfDices; d++){
    delete defendDices[d];
  }
  delete attackDices;
  delete defendDices;
  return casualties;
}

void DiceRolling::sort(Die** dArray, int arraySize){ //most basic sort because amount of dice is always low
  for(int i = 0; i < arraySize-1; i++){
    for(int j = i+1; j < arraySize; j++){
      if(dArray[i]->dieSide < dArray[j]->dieSide){
        swap(dArray[i], dArray[j]);
      }
    }
  }
}

DiceRolling::~DiceRolling(){}
