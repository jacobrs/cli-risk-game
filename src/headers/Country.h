#ifndef COUNTRY_H
#define COUNTRY_H

#include "Player.h"
#include <string>

using namespace std;
class Player;
class Country{
public:

  int armies;
  int numberOfNeighbours; // need to keep track of this since
                          // using traditional dynamic arrays
  string name;
  Player* owner;
  Country **neighbours;

  Country();
  Country(string);
  bool hasEnnemies();
  void listEnnemies();
  string getWeakestEnemy();
  string getRandonEnemy();
  void addNeighbour(Country*);
  bool isNeighbour(Country*);
};

#endif
