#include "headers/Player.h"
#include "headers/Country.h"
#include "headers/Continent.h"
#include "headers/GameMap.h"
#include "headers/HumanPlayer.h"
#include "headers/AggressivePlayer.h"
#include "headers/BenevolentPlayer.h"
#include "headers/GameStart.h"
#include "headers/StartupPhase.h"
#include "headers/Game.h"
#include "headers/GameView.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

  srand (time(NULL));

  string selectedMap;
  int numOfPlayers = 0;
  bool promptPlayers = true;
  bool promptMap = true;

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
  GameMap* map = newGame -> gameMap;

  string playerType = "";
  for(int i = 0; i < newGame->players.size(); i++){
    newGame->players.at(i)->setStrategy(new HumanPlayer());
  }

  StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
  Game *game = new Game(newGame->gameMap, newGame->players);

  for (int i = 0; i<game->players.size(); i++){
    string deco;
    if(!(game -> players.at(i) -> decorators[0])){
      while(deco != "4"){
        cout << "Which decorators would you like to enable/disable?" << endl;
        cout << "[0] Don't ask again" << endl;
        cout << "[1] Player Domination Observer Decorator" << endl;
        cout << "[2] Player Hands Observer Decorator" << endl;
        cout << "[3] Continent Control Observer Decorator" << endl;
        cout << "[4] DONE" << endl;
        cin >> deco;

        if(deco == "0"){
          game -> players.at(i) -> decorators[0] = true;
        }else if( deco == "1"){
          game -> players.at(i) -> decorators[1] = true;
        }else if( deco == "2"){
          game -> players.at(i) -> decorators[2] = true;
        }else if( deco == "3"){
          game -> players.at(i) -> decorators[3] = true;
        }
      }
    }
    game -> players.at(i) -> reinforce(map);
    game -> stateChanges -> Notify(map, game->players, game->players.at(i)-> turns);
    game -> players.at(i) -> attack(map);
    game -> stateChanges -> Notify(map, game->players, game->players.at(i)-> turns);
    game -> players.at(i) -> turns++;
  }
  return 0;
}
