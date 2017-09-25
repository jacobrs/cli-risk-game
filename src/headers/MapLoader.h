#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <string>

using namespace std;

class MapLoader{
public:
  string mapPath;

  MapLoader(string);
  bool importMap();
};

#endif
