#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "Continent.h"
#include "GameMap.h"
#include <string>

using namespace std;

class Continent;
class Country;
class GameMap{
public:

  int numberOfContinents;

  Continent **continents;

  GameMap();
  Country* getCountryByName(string);
  void addContinent(Continent*);
  bool isValidMap();

};

#endif
