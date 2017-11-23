#include "../headers/Tournament.h"
#include "../headers/GameStart.h"
#include "../headers/MapLoader.h"
#include "../headers/GameMap.h"
#include "../headers/Deck.h"
#include "../headers/StartupPhase.h"
#include "../headers/Game.h"
#include "../headers/AggressivePlayer.h"
#include "../headers/RandomPlayer.h"
#include "../headers/BenevolentPlayer.h"
#include "../headers/CheaterPlayer.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

Tournament::~Tournament(){
  delete maps;
  delete strats;
  maps = NULL;
  strats = NULL;
}

// default tournament
Tournament::Tournament(){
  nbMaps = 2;
  nbStrats = 2;
  nbGames = 2;
  nbTurns = 50;
  maps[0] = "World";
  maps[1] = "Dice";
  strats[0] = "a";
  strats[1] = "b";
}

// custom tournament
Tournament::Tournament(int nbOfMaps, int nbOfStrats, int nbOfGames, int nbOfTurns, const string* newMaps, const string* newStrats){
  nbMaps = nbOfMaps;
  nbStrats = nbOfStrats;
  nbGames = nbOfGames;
  nbTurns = nbOfTurns;
  maps = newMaps;
  strats = newStrats;
}

void Tournament::startTournament(){
  for(int game = 0; game < nbGames; game++){
    GameStart* newGame = new GameStart(maps[game], nbStrats);
    string playerType = "";
    for(int i = 0; i < nbStrats; i++){
      if(strats[i] == "a"){
        newGame->players.at(i)->setStrategy(new AggressivePlayer());
      }
      else if (strats[i] == "b"){
        newGame->players.at(i)->setStrategy(new BenevolentPlayer());
      }
      else if(strats[i] == "c"){
        newGame->players.at(i)->setStrategy(new CheaterPlayer());
      }
      else if(strats[i] == "r"){
        newGame->players.at(i)->setStrategy(new RandomPlayer());
      }
      else{
        cout << "ERROR IN TOURNAMENT PLAYER STRATS" << endl;
      }
    }
    StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
    Game *match = new Game(newGame->gameMap, newGame->players);
    match->startGame();
  }
}
