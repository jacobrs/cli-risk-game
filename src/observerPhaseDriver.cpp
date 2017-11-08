#include "headers/GameView.h"
#include "headers/Player.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

    //Create a GamePlay to be observed
    Player* p = new Player;

    //Create a GameView that is connected to the GamePlay
    GameView *gameview1 = new GameView(p);

    cout << "What phase would you like to observe? (attack, reinforce or fortify)" << endl;
    string  phase = "";
    cin >> phase;

    bool observe = true;

    while (observe){
        // First possible scenario is Attack Phase
      if (phase.compare("attack")==0){
        srand (time(NULL)); // seeding random 
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
      
        Player* FOO = new Player(1,"foo","red");
        Player* BAR = new Player(2,"bar","blue");
      
        canada->armies=10;
        canada->owner=FOO;
        mexico->armies=10;
        mexico->owner=FOO;
        usa->armies=2;
        usa->owner=BAR;
        
        FOO->attack(map);
     
    } //Second scenario Fortify phase
    else if(phase.compare("fortify")==0){

    } // Third scenario Reinforce phase
    else if(phase.compare("reinforce")==0){

    } else {
        cout << "Invalid phase, enter proper phase: " << endl;
        phase = "";
        cin >> phase
        return;
    }

    cout << "Do you want to see another scenario? (y/n)" << endl;
    string choice = "";
    cin >> choice;
    if (choice.compare("n")==0)
        observe = false;


}

    return 0;
}