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
  const char* mapPath;
	vector<Continent> mapContinents;
	vector<Country> mapCountries;
  
  MapLoader(const char*);
  void importMap();
};

#endif
