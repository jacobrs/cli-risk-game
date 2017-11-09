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

/*
    cout << "Choose a scenario (attack or fortify): " << endl;
    string scenario = "";
    cin >> scenario;

    //Create 2 players, but FOO is the one being observed
    Player *FOO = new Player(1, "Foo", "blue");
    Player *BAR = new Player(2,"bar","blue");
    GameView *gameView = new GameView(FOO);

    bool observing = true;
    while(observing){
    //Attack scenario
    if(scenario.compare("attack")==0){
        srand (time(NULL)); // seeding random VERY IMPORTANT!!!!
        // temporary testing code
        Continent* northAmerica = new Continent("North America", 5);
        Continent* southAmerica = new Continent("South America", 2);
      
        Country* canada = new Country("Canada");
        Country* usa = new Country("USA");
        Country* mexico = new Country("Mexico");
        Country* venezuela = new Country("Venezuela");
        Country* brazil = new Country("Brazil");
        Country* argentina = new Country("Argentina");
        Country* chile = new Country("Chile");
        Country* cuba = new Country("Cuba");
      
        usa->addNeighbour(canada);
        usa->addNeighbour(mexico);
        cuba->addNeighbour(mexico);
        brazil->addNeighbour(argentina);
        brazil->addNeighbour(venezuela);
        brazil->addNeighbour(chile);
        chile->addNeighbour(venezuela);
        chile->addNeighbour(argentina);
        // link continents together
        venezuela->addNeighbour(mexico);
      
        northAmerica->addCountry(canada);
        northAmerica->addCountry(usa);
        northAmerica->addCountry(mexico);
        southAmerica->addCountry(venezuela);
        southAmerica->addCountry(brazil);
        southAmerica->addCountry(chile);
        southAmerica->addCountry(argentina);
        southAmerica->addCountry(cuba);
      
        GameMap* map = new GameMap();
        map->addContinent(northAmerica);
        map->addContinent(southAmerica);
      
        map->isValidMap();
      
        canada->armies=10;
        canada->owner=FOO;
        mexico->armies=10;
        mexico->owner=FOO;
        usa->armies=2;
        usa->owner=BAR;
        
        FOO->attack(map);

    }else if(scenario.compare("fortify")==0){

    } else {
        cout << "Invalid input" << endl;
    }

    cout << "Do you want to see another scenario? (y/n)" << endl;
    string answer = "";
    cin >> answer;

    if (answer == "n"){
        observing = false;
    } else if (answer == "y"){

    } else{
        cout << "Invalid input, stop observing." << endl;
        observing = false;
    }
}

*/




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

