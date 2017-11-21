#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
#include "DiceRolling.h"
#include "Country.h"
#include "GameMap.h"
#include "Subject.h"
#include "Strategy.h"

using namespace std;
class Country;
class GameMap;
class Strategy;
class Player : public Subject{
private:
  Strategy *strategy;
public:
  int index;
  string name;
  string color;
  Hand *hand;

  Player(int, string, string);
  Player();
  Player(Strategy *initStrategy){
    this->strategy = initStrategy;
  }
  void setStrategy(Strategy *newStrategy){
    this->strategy = newStrategy;
  }
  void executeStrategy(GameMap*);
  //void reinforce();
  void attack(GameMap*);
  void reinforce(GameMap*);
  bool fortify(Country*, Country*, int);
  void listMyAttackCountries(GameMap*);
  bool ownsAttackCountry(GameMap*);
  string getStrongetAttackCountry(GameMap*);
  string getStrongetCountry(GameMap*);
  string getWeaketCountry(GameMap*);
  string getRandomAttackCountry(GameMap*);
  string getRandomCountry(GameMap*);
  ~Player();
  
};

#endif
