#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Continent.h"
#include "Country.h"

#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class MapLoader{
public:
  bool isValid;
  const char* mapPath;
	vector<Continent*> mapContinents;
	vector<Country*> mapCountries;
  
  MapLoader(const char*);
  ~MapLoader();
  void importMap();
  void importContinent(string);
  void importCountry(string);
  void importNeighbours(string);
};

#endif
