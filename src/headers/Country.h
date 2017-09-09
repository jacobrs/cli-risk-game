#ifndef COUNTRY_H
#define COUNTRY_H

#include "Player.h"
#include <string>

using namespace std;

class Country{
public:
  
  int armies;
  int numberOfNeighbours; // need to keep track of this since
                          // using traditional dynamic arrays
  string name;
  Player* owner;
  Country* neighbours;

  Country();
  ~Country();
  Country(string);
  void addNeighbour(Country);

};

#endif
