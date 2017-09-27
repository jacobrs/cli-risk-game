#include "headers/MapLoader.h"

using namespace std;

int main(int args, char** argv){

  // Instantiation of game object goes here.

  // temporary testing code

  MapLoader* mapLoader = new MapLoader("src/map/World.map");
  mapLoader->importMap();
}
