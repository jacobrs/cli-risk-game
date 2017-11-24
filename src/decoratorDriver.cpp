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
#include "headers/CountryObserverDecorator.h"
#include "headers/HandObserverDecorator.h"
#include "headers/ContinentObserverDecorator.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

  srand (time(NULL)); 

  string selectedMap;
  int numOfPlayers = 0;
  bool promptPlayers = true;
  bool promptMap = true;

  bool dominationDecorator = false;
  bool handDecorator = false;
  bool continentDecorator = false;
     
  bool lockDecorators = false;

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
    newGame->players.at(i)->setStrategy(new AggressivePlayer());
  }

  StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
  Game *game = new Game(newGame->gameMap, newGame->players);

  CountryObserverDecorator* countryObv = new CountryObserverDecorator(game->stateObserver);
  HandObserverDecorator* handObv = new HandObserverDecorator(game->stateObserver);
  ContinentObserverDecorator* continentObv = new ContinentObserverDecorator(game->stateObserver);
  
  while(!game->isWon()){
    for(int i = 0; i<game->players.size(); i++){
      char input;
      
      if(!lockDecorators){
        if(!dominationDecorator){
          cout << "Enable domination decorator? [Yy]" << endl;
          cin >> input;
          if(toupper(input) == 'Y'){
            game->stateChanges->Attach(countryObv);
            dominationDecorator = true;
          }
        }else{
          cout << "Disable domination decorator? [Yy]" << endl;
          cin >> input;
          if(toupper(input) == 'Y'){
            game->stateChanges->Detach(countryObv);
            dominationDecorator = false;
          }
        }

        if(!handDecorator){
          cout << "Enable hand decorator? [Yy]" << endl;
          cin >> input;
          if(toupper(input) == 'Y'){
            game->stateChanges->Attach(handObv);
            handDecorator = true;
          }
        }else{
          cout << "Disable hand decorator? [Yy]" << endl;
          cin >> input;
          if(toupper(input) == 'Y'){
            game->stateChanges->Detach(handObv);
            handDecorator = false;
          }
        }

        if(!continentDecorator){
          cout << "Enable continent decorator? [Yy]" << endl;
          cin >> input;
          if(toupper(input) == 'Y'){
            game->stateChanges->Attach(continentObv);
            continentDecorator = true;
          }
        }else{
          cout << "Disable continent decorator? [Yy]" << endl;
          cin >> input;
          if(toupper(input) == 'Y'){
            game->stateChanges->Detach(continentObv);
            continentDecorator = false;
          }
        }

        cout << "Lock decorator configuration? [Yy]" << endl;
        cin >> input;
        if(toupper(input) == 'Y'){
          lockDecorators = true;
        }
      }
      
      game->players.at(i)->reinforce(map);
      game->stateChanges->Notify(map, game->players);
      game -> players.at(i) -> attack(map);
      game -> players.at(i)->hand->addCard(newGame->playDeck->draw());
      game->stateChanges->Notify(map, game->players);

      if(game->isWon())
        break;
    }
  }

  return 0;
}

