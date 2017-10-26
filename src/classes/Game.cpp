#include "../headers/Game.h"
#include "../headers/GameMap.h"

Game::Game(GameMap* map, int numberOfPlayers){
  gameMap = map;
}

Game::~Game(){
  delete gameMap;
}
