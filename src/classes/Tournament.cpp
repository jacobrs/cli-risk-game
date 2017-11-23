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
  maps = newMaps;
  strats = newStrats;
}

void Tournament::startTournament(){
  vector<string> tournamentStats;
  for(int game = 0; game < nbGames; game++){
    string statString = "Game " + to_string(game) + ": \n";
    GameStart* newGame = new GameStart(maps[game], nbStrats);
    statString += "Map " + to_string(game) + ": " + maps[game] + "\n";
    string playerType = "";
    for(int i = 0; i < nbStrats; i++){
      statString += "Player " + to_string(i) + ": ";
      if(strats[i] == "a"){
        newGame->players.at(i)->setStrategy(new AggressivePlayer());
        statString += "Aggressive\n";
      }
      else if (strats[i] == "b"){
        newGame->players.at(i)->setStrategy(new BenevolentPlayer());
        statString += "Benevolent\n";
      }
      else if(strats[i] == "c"){
        newGame->players.at(i)->setStrategy(new CheaterPlayer());
        statString += "Cheater\n";
      }
      else if(strats[i] == "r"){
        newGame->players.at(i)->setStrategy(new RandomPlayer());
        statString += "Random\n";
      }
      else{
        cout << "ERROR IN TOURNAMENT PLAYER STRATS" << endl;
      }
    }
    StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
    Game *match = new Game(newGame->gameMap, newGame->players);
    statString += "The winner of the game is: " + match->startGame();

    tournamentStats.push_back(statString);
    delete match;
    delete startGame;
    delete newGame;
  }
  for(int i = 0; i < nbGames; i++){
    cout<<tournamentStats[nbGames]<<endl;
  }
}
