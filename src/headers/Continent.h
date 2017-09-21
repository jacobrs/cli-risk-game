#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"
#include <string>

using namespace std;

class Continent{
public:
  
  int bonus;
  int numberOfCountries;

  string name;
  Country **countries;

  Continent();
  Continent(string, int);
  void addCountry(Country*);

};

#endif
