#include "headers/Player.h"
#include "headers/Country.h"
#include "headers/Continent.h"
#include "headers/GameMap.h"
#include "headers/HumanPlayer.h"
#include "headers/AggressivePlayer.h"
#include "headers/RandomPlayer.h"
#include "headers/BenevolentPlayer.h"
#include "headers/GameStart.h"
#include "headers/StartupPhase.h"
#include "headers/Game.h"

using namespace std;

int main(int args, char** argv){

  srand (time(NULL)); 

  string selectedMap;
  int numOfPlayers = 0;
  bool promptPlayers = true;
  bool promptMap = true;
  vector <Player> players;
     
  // Validates the number of players
  while (promptPlayers){
      cout << "Number of Players between 2-6: " << endl;
      cin >> numOfPlayers;

      if (numOfPlayers < 2 || numOfPlayers >6){ 
          cout << "Please enter correct number of players" << endl;
         } 
      else{
          promptPlayers =false;
      }
  }
  //validates the map chosen
  while (promptMap){
      cout << "Select Map File: Khoras or World" << endl;
      cin >> selectedMap;

      if (selectedMap.compare("Khoras") == 0 || selectedMap.compare("World") == 0){ 
          promptMap =false;

         } 
      else{
          cout << "Please enter the correct filename" << endl;
      }
  }

  GameStart* newGame = new GameStart(selectedMap, numOfPlayers);

  string playerType = "";
  for(int i = 0; i < newGame->players.size(); i++){
    cout<<"What type of player is " << newGame->players.at(i)->name << "?"<< endl;
    cout<<"Enter H for Human, A for Aggressive, B for benevolent and R for random"<< endl;
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
    else if(playerType == "R" || playerType == "r"){
      newGame->players.at(i)->setStrategy(new RandomPlayer());
    }
    else{
      cout<< "You did not enter a correct value for a player type. By default it will be a benevolent player"<< endl;
      newGame->players.at(i)->setStrategy(new BenevolentPlayer());
    }
  }
  StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
  Game *game = new Game(newGame->gameMap, newGame->players);
  game->startGame();
  return 0;
}