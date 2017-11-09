#include <iostream>
#include "./headers/Game.h"
#include "./headers/GameMap.h"
#include "./headers/MapLoader.h"

using namespace std;

int main(int args, char** argv){
  
  // Initialize a new game with a valid map
  MapLoader* loader = new MapLoader("./src/map/World.map");
  loader->importMap();
  GameMap* map = loader->exportToGameMap();

  // verify that the map was loaded in properly
  printf("Checking integrity of game map\n\n");
  map->isValidMap();
  vector<Player*> initPlayers;
  initPlayers.push_back(new Player(0, "Tester1", "red"));
  initPlayers.push_back(new Player(1, "Tester2", "blue"));
  
  printf("Starting main game loop\n");
  Game *game = new Game(map, 2, initPlayers);
  game->startGame();

  delete loader;
  delete game;
}
