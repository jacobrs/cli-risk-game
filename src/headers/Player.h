#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
#include "DiceRolling.h"

using namespace std;

class Player{
public:
  int index;
  string name;
  string color;
  Hand *hand;
  DiceRolling *diceRollingFacility;

  Player(int, string, string, int);
  Player();
  void reinforce();
  void attack();
  void fortify();
  ~Player();
};

#endif
