#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "Continent.h"
#include <string>

using namespace std;

class GameMap{
public:
  
  int numberOfContinents;

  Continent **continents;

  GameMap();
  void addContinent(Continent*);

};

#endif
