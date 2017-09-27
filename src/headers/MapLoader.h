#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <fstream>
#include <string>

using namespace std;

class MapLoader{
public:
  const char* mapPath;
  
  MapLoader(const char*);
  bool importMap();
};

#endif
