#include "../headers/Game.h"
#include "../headers/Player.h"
#include "../headers/GameMap.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Game::Game(GameMap* map, vector<Player*> initPlayers){
  gameMap = map;
  players = initPlayers;
  stateChanges = new GameSubject();
  stateObserver = new GameStateObserver();
  stateChanges->Attach(stateObserver);
}

Game::~Game(){
  delete gameMap;
  gameMap = NULL;
  delete stateChanges;
  stateChanges = NULL;
  delete stateObserver;
  stateObserver = NULL;
  for(int i = 0; i < players.size(); i++){
    delete players.at(i);
    players.at(i) = NULL;
  }
}

string Game::isWon(){
  string winnerName = "None";
  if(gameMap->continents[0]->countries[0]->owner != NULL){
    winnerName = gameMap->continents[0]->countries[0]->owner->name;
  }
  else{
    return "None";
  }

  for(int i = 0; i < gameMap->numberOfContinents; i++){
    for(int j = 0; j < gameMap->continents[i]->numberOfCountries; j++){
      if(gameMap->continents[i]->countries[j]->owner->name != winnerName){
        return "None";
      }
    }
  }

  return winnerName;
}

string Game::startGame(){

  int i = 0;
  int currentPlayer = 0;
  while(true){
    printf("Playing iteration %d\n", i);

    printf("Player %s's turn\n", players[currentPlayer]->name.c_str());

    stateChanges->Notify(gameMap, players);
    players[currentPlayer]->executeStrategy(gameMap);

    currentPlayer = (currentPlayer + 1) % players.size();

    if(this->isWon() != "None")
      break;
  }
  printf("notify win\n");
  stateChanges->Notify(gameMap, players);
  printf("Game was won!\n");
  printf("first won\n");
  printf("after first won\n");
  return this->isWon();

}

void Game::observeGame(){

  cout << "in observe" << endl;
  while(true){

    for (int i = 0; i < players.size() ; i++){

      cout << "Iteration " << i <<endl;
      players.at(i)->reinforce(gameMap);

      players.at(i)->attack(gameMap);

      bool fortifying = true;
      while (fortifying){

        cout << "What country do you want to fortify?" << endl;
        string armingCountry = "";
        cin >> armingCountry;
        Country* arming = gameMap->getCountryByName(armingCountry);

        cout << "Which country are the armies coming from?" << endl;
        string armlessCountry = "";
        cin >> armlessCountry;
        Country* armless = gameMap->getCountryByName(armlessCountry);

        cout << "How many armies are you moving?" << endl;
        int nbarmy =0;
        cin >> nbarmy;
        players.at(i)->fortify(arming, armless, nbarmy);

        cout << "Do you want to continue fortifying? (y/n)";
        string answer ="";
        cin >> answer;
        if(answer == "n"){
          fortifying = false;
        }
      }
    }
    if(this->isWon() != "None")
      break;
  }
  stateChanges->Notify(gameMap, players);
  printf("second won\n");
  printf("Game was won!\n");

}
