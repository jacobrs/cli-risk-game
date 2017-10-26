#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "Continent.h"
#include "GameMap.h"
#include <string>

using namespace std;

class GameMap{
public:
  
  int numberOfContinents;

  Continent **continents;

  GameMap();
  void addContinent(Continent*);
  bool isValidMap();

};

#endif
