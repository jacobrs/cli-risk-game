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

int main(int args, char** argv){

  srand (time(NULL));

  string selectedMap;
  int numOfPlayers = 0;
  bool promptPlayers = true;
  int numOfMaps = 0;
  bool promptNbMaps = true;
  int numOfGames = 0;
  bool promptNbGames = true;
  int numOfTurns = 0;
  bool promptNbTurns = true;
  vector <Player> players;

  // Validates the number of player strategies
  while (promptPlayers){
      cout << "Number of Player strategies between 2-4: " << endl;
      cin >> numOfPlayers;

      if (numOfPlayers < 2 || numOfPlayers > 4){
          cout << "Please enter correct number of player strategies" << endl;
         }
      else{
          promptPlayers =false;
      }
  }
  //select player strategies
  string[numOfPlayers] playerTypes;;
  while(numOfPlayers-- > 0){
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
  }
  // Validates the number of maps
  while (promptNbMaps){
      cout << "Number of maps to be played between 1-5: " << endl;
      cin >> numOfMaps;

      if (numOfMaps < 1 || numOfMaps > 5){
          cout << "Please enter correct number of maps to be played" << endl;
         }
      else{
          promptNbMaps =false;
      }
  }
  //validates the map chosen
  while(numOfMaps-- > 0){
    bool promptMap = true;
    while (promptMap){
      printf("Map Nb.%d",numOfMaps);
      cout << "Select Map File: Atlantis, Dice, Khoras, Swamp, or World" << endl;
      cin >> selectedMap;

      if (selectedMap.compare("Khoras") == 0 || selectedMap.compare("World") == 0 || selectedMap.compare("Dice") == 0 || selectedMap.compare("Swamp") == 0 || selectedMap.compare("Atlantis") == 0){
        promptMap =false;
      }
      else{
        cout << "Please enter the correct filename" << endl;
      }
    }
  }
  // Validates the number of games
  while (promptNbGames){
      cout << "Number of games to be played between 1-5: " << endl;
      cin >> numOfGames;

      if (numOfGames < 1 || numOfGames > 5){
          cout << "Please enter correct number of games to be played" << endl;
         }
      else{
          promptNbGames =false;
      }
  }
  // Validates the number of turns
  while (promptNbTurns){
      cout << "Number of turns in a game between 10-50: " << endl;
      cin >> numOfTurns;

      if (numOfTurns < 10 || numOfTurns > 50){
          cout << "Please enter correct number of turns in a game" << endl;
         }
      else{
          promptNbTurns =false;
      }
  }
  return 0;
}
