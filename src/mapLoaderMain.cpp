#include "headers/MapLoader.h"

using namespace std;

int main(int args, char** argv){

  // Instantiation of game object goes here.

  // temporary testing code

  printf("\n\nEXPECTING FILE NOT FOUND\n");
  MapLoader* fileNotFound = new MapLoader("src/map/BEEPBEEP.map");
  fileNotFound->importMap();

  printf("\n\nEXPECTING MAP FILE THAT DOES NOT CONTAIN CONTINENTS\n");
  MapLoader* noContinent = new MapLoader("src/map/noContinent.map");
  noContinent->importMap();

  printf("\n\nEXPECTING MAP FILE THAT DOES NOT CONTAIN COUNTRIES\n");
  MapLoader* noCountry = new MapLoader("src/map/noCountry.map");
  noCountry->importMap();

  printf("\n\nEXPECTING CORRECT FILE PATH AND FILE FORMAT\n");
  MapLoader* mapLoader = new MapLoader("src/map/World.map");
  mapLoader->importMap();
}
