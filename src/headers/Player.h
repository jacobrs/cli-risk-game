#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
#include "DiceRolling.h"
#include "Country.h"
#include "GameMap.h"
<<<<<<< HEAD
#include "Subject.h"
=======
#include "Strategy.h"
>>>>>>> e44a72db5dd88edf97a79010d31133dc37b1a1d0

using namespace std;
class Country;
class GameMap;
<<<<<<< HEAD
class Player : public Subject{
=======
class Strategy;
class Player{
private:
  Strategy *strategy;
>>>>>>> e44a72db5dd88edf97a79010d31133dc37b1a1d0
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

  ~Player();
  
};

#endif
