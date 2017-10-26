#include <iostream>
#include "./headers/Game.h"
#include "./headers/GameMap.h"
#include "./headers/MapLoader.h"

using namespace std;

int main(int args, char** argv){
  
  // Initialize a new game with a valid map
  MapLoader* loader = new MapLoader("./map/World.map");
  loader->importMap();
  GameMap* map = loader->exportToGameMap();
  delete loader;

  // verify that the map was loaded in properly
  printf("Checking integrity of game map\n\n");
  map->isValidMap();

  printf("Starting main game loop\n");
  Game game = Game(map);
  

  // clean up pointers 
  delete map;
  
  return 0;
}
