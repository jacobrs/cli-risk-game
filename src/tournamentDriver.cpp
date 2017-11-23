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
#include "headers/Tournament.h"

#include <iostream>
#include <string>

using namespace std;

int main(int args, char** argv){

  srand (time(NULL));

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
      cout << endl << "Number of Player strategies between 2-4: " << endl;
      cin >> numOfPlayers;

      if (numOfPlayers < 2 || numOfPlayers > 4){
          cout << "Please enter correct number of player strategies" << endl;
         }
      else{
          promptPlayers =false;
      }
  }
  //select player strategies
  vector<string> playerTypes;
  for(int i = 0; i < numOfPlayers; i++){
    cout << endl << "Enter strategy number " << i+1 << endl;
    cout<<"Enter A for Aggressive, B for Benevolent, C for Cheater and R for random"<< endl;
    string input = "";
    cin>> input;
    if(input == "A" || input == "a"){playerTypes.push_back("a");}
    else if (input == "B" || input == "b"){playerTypes.push_back("b");}
    else if(input == "C" || input == "c"){playerTypes.push_back("c");}
    else if(input == "R" || input == "r"){playerTypes.push_back("r");}
    else{
      cout << "You did not enter a correct value for a player type. By default it will be a benevolent player"<< endl;
      playerTypes.push_back("b");
    }
    /*for(int j = 0; j < i; j++){
      if(playerTypes[j].compare(playerTypes[i]) == 0){
        cout << "This strategy is already entered, choose another one." << endl;
        i--;
      }
    }*/
  }
  // Validates the number of maps
  while (promptNbMaps){
      cout << endl << "Number of maps to be played between 1-5: " << endl;
      cin >> numOfMaps;

      if (numOfMaps < 1 || numOfMaps > 5){
          cout << "Please enter correct number of maps to be played" << endl;
         }
      else{
          promptNbMaps =false;
      }
  }
  //validates the map chosen
  vector<string> selectedMaps;
  for(int mapNb = 0; mapNb < numOfMaps; mapNb++){
    bool promptMap = true;
    while (promptMap){
      cout << "Select Map File number " << mapNb+1 << ": Atlantis, Dice, Khoras, Swamp, or World" << endl;
      string input = "";
      cin >> input;

      if (input =="Khoras"|| input == "World" || input == "Dice" || input == "Swamp" || input == "Atlantis"){
        selectedMaps.push_back(input);
        promptMap =false;
      }
      else{
        cout << "Please enter the correct filename" << endl;
      }
    }
    for(int j = 0; j < mapNb; j++){
      if(selectedMaps[j] == selectedMaps[mapNb]){
        cout << "This map is already entered, choose another one." << endl;
        mapNb--;
      }
    }
  }
  // Validates the number of games
  while (promptNbGames){
      cout << endl << "Number of games to be played between 1-5: " << endl;
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
      cout << endl << "Number of turns in a game between 10-50: " << endl;
      cin >> numOfTurns;

      if (numOfTurns < 10 || numOfTurns > 50){
          cout << "Please enter correct number of turns in a game" << endl;
         }
      else{
          promptNbTurns =false;
      }
  }

  cout << endl << "===== TOURNAMENT SETTINGS ======" << endl;
  cout << "Nb of Strategies: " << numOfPlayers << endl;
  cout << "Nb of Maps: " << numOfMaps << endl;
  cout << "Nb of Games: " << numOfGames << endl;
  cout << "Max Nb of Turns: " << numOfTurns << endl;
  for(int i = 0; i < numOfPlayers; i++){
    cout << "Strategy nb " << i+1 << " is " << playerTypes[i] << endl;
  }
  for(int i = 0; i < numOfMaps; i++){
    cout << "Map nb " << i+1 << " is " << selectedMaps[i] << endl;
  }

  Tournament* tour = new Tournament(numOfMaps, numOfPlayers, numOfGames, numOfTurns, selectedMaps, playerTypes);

  tour -> startTournament();

  return 0;
}
