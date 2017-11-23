#include "../headers/GameStart.h"
#include "../headers/MapLoader.h"
#include "../headers/GameMap.h"
#include "../headers/Deck.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

Tournament::Tournament(){

}


void Tournament::startTournament(){
  GameStart* newGame = new GameStart(selectedMap, numOfPlayers);

  string playerType = "";
  for(int i = 0; i < newGame->players.size(); i++){
    cout<<"What type of player is " << newGame->players.at(i)->name << "?"<< endl;
    cout<<"Enter H for Human, A for Aggressive and B for benevolent"<< endl;
    cin>> playerType;
    if(playerType == "H" || playerType == "h"){
      newGame->players.at(i)->setStrategy(new HumanPlayer());
    }
    else if(playerType == "A" || playerType == "a"){
      newGame->players.at(i)->setStrategy(new AggressivePlayer());
    }
    else if (playerType == "B" || playerType == "b"){
      newGame->players.at(i)->setStrategy(new BenevolentPlayer());
    }
    else{
      cout<< "You did not enter a correct value for a player type. By default it will be a benevolent player"<< endl;
      newGame->players.at(i)->setStrategy(new BenevolentPlayer());
    }
  }
  StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
  Game *game = new Game(newGame->gameMap, newGame->players);
  game->startGame();
}
