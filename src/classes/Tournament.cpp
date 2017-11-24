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
  //delete maps;
  //delete strats;
  //maps = NULL;
  //strats = NULL;
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
Tournament::Tournament(int nbOfMaps, int nbOfStrats, int nbOfGames, int nbOfTurns, vector<string> newMaps, vector<string> newStrats){
  nbMaps = nbOfMaps;
  nbStrats = nbOfStrats;
  nbGames = nbOfGames;
  nbTurns = nbOfTurns;
  for(int i = 0; i < nbOfMaps; i++){
    maps.push_back(newMaps.at(i));
  }
  for(int i = 0; i < nbOfStrats; i++){
    strats.push_back(newStrats.at(i));
  }
}

void Tournament::startTournament(){
  vector<string> tournamentStats;
  for(int game = 0; game < nbGames; game++){
    cout << "game loop" <<endl;
    string statString = "Game " + to_string(game) + ": \n";
    GameStart* newGame = new GameStart(maps.at(game), nbStrats);
    statString += "Map " + to_string(game) + ": " + maps.at(game) + "\n";
    string playerType = "";
    for(int i = 0; i < nbStrats; i++){
      statString += "Player " + to_string(i) + ": ";
      if(strats.at(i) == "a"){
        newGame->players.at(i)->setStrategy(new AggressivePlayer());
        statString += "Aggressive\n";
      }
      else if (strats.at(i) == "b"){
        newGame->players.at(i)->setStrategy(new BenevolentPlayer());
        statString += "Benevolent\n";
      }
      else if(strats.at(i) == "c"){
        newGame->players.at(i)->setStrategy(new CheaterPlayer());
        statString += "Cheater\n";
      }
      else if(strats.at(i) == "r"){
        newGame->players.at(i)->setStrategy(new RandomPlayer());
        statString += "Random\n";
      }
      else{
        cout << "ERROR IN TOURNAMENT PLAYER STRATS" << endl;
      }
    }
    StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
    cout << "post startupphase" << endl;
    Game *match = new Game(newGame->gameMap, newGame->players);
    cout << "post game" << endl;
    statString += "The winner of the game is: " + match->startGame();
    cout << "post startGame()";
    tournamentStats.push_back(statString);
    delete match;
    delete startGame;
    delete newGame;
    match = NULL;
    startGame = NULL;
    newGame = NULL;
  }
  for(int i = 0; i < nbGames; i++){
    cout<<tournamentStats.at(nbGames)<<endl;
  }
}
