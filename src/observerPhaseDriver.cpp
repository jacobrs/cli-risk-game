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
  GameMap* map = newGame -> gameMap;

  string playerType = "";
  for(int i = 0; i < newGame->players.size(); i++){

      newGame->players.at(i)->setStrategy(new HumanPlayer());
    
  }

  StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
  Game *game = new Game(newGame->gameMap, newGame->players);

  
      for (int i = 0; i<game->players.size(); i++){
    //Set the observer to look at each player while they are going through their turn
         GameView *gameView = new GameView(game ->players.at(i));
    //Subject does the reinforcement phase
         game -> players.at(i) -> reinforce(map);
    //Subject does their attack phase
         game -> players.at(i) -> attack(map);
    

}
    return 0;
}

