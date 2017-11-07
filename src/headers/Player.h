#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
#include "DiceRolling.h"
#include "Country.h"
#include "GameMap.h"
#include "Subject.h"

using namespace std;
class Country;
class GameMap;
class Player : public Subject{
public:
  int index;
  string name;
  string color;
  Hand *hand;

  Player(int, string, string);
  Player();
  void reinforce();
  void attack(GameMap*);
  void reinforce(GameMap*);
  bool fortify(Country*, Country*, int);
  void listMyAttackCountries(GameMap*);
  bool ownsAttackCountry(GameMap*);

  void mockFortify();
  void mockAttack();
  void mockReinforce();

  ~Player();
  
};

#endif
