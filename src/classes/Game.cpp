#include "../headers/Game.h"
#include "../headers/Player.h"
#include "../headers/GameMap.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Game::Game(GameMap* map, int numberOfPlayers){
  gameMap = map;
  players.push_back(new Player(0, "Tester1", "red"));
  players.push_back(new Player(1, "Tester2", "blue"));
}

Game::~Game(){
  if(gameMap != NULL)
    delete gameMap;
}

bool Game::isWon(){
  string winnerName = "None";
  if(gameMap->continents[0]->countries[0]->owner != NULL){
    winnerName = gameMap->continents[0]->countries[0]->owner->name;
  }
  else{
    return false;
  }

  for(int i = 0; i < gameMap->numberOfContinents; i++){
    for(int j = 0; j < gameMap->continents[i]->numberOfCountries; j++){
      if(gameMap->continents[i]->countries[j]->owner->name != winnerName){
        return false;
      }
    }
  }

  return true;
}

void Game::startGame(){

  int i = 0;
  int currentPlayer = 0;
  while(true){
    printf("Playing iteration %d\n", i);

    printf("Player %s's turn\n", players[currentPlayer]->name.c_str());

    printf("Reinforcement Phase\n");
    printf("Attack Phase\n");
    printf("Fortification Phase\n");
    i ++;
    if(i > 5){
      printf("giving everything to a player\n");
      break;
    }
    currentPlayer = (currentPlayer + 1) % players.size();

    if(this->isWon() == true)
      break;
  }

  printf("Game was won!\n");

}
