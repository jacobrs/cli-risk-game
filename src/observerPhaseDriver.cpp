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
      
//        map->isValidMap();
      
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
  cout << "Gamestart done" << endl;
  GameMap* map = newGame -> gameMap;
/*
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
  */

  StartupPhase* startGame = new StartupPhase(newGame->gameMap, newGame->players);
  cout << "Startup phase done" << endl;
  Game *game = new Game(newGame->gameMap, newGame->players);
  cout << "Game" << endl;


  for (int i = 0; i<players.size(); i++){
    cout << "in for loop" << endl;
    GameView *gameView = new GameView(newGame ->players.at(i));
    cout << "observer" << endl;
    newGame -> players.at(i) -> reinforce(map);
    cout << "reinforce done" << endl;
    newGame -> players.at(i) -> attack(map);
    cout << "attack done" << endl;

    bool fortifying = true;
    while (fortifying){
        
              cout << "What country do you want to fortify?" << endl;
              string armingCountry = "";
              cin >> armingCountry;
              Country* arming = map->getCountryByName(armingCountry);
        
              cout << "Which country are the armies coming from?" << endl;
              string armlessCountry = "";
              cin >> armlessCountry;
              Country* armless = map->getCountryByName(armlessCountry);
        
              cout << "How many armies are you moving?" << endl;
              int nbarmy =0;
              cin >> nbarmy;
              newGame -> players.at(i)->fortify(arming, armless, nbarmy);
            }



  }
  


    return 0;
}

