#include "headers/GameView.h"
#include "headers/Player.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

    cout << "Choose a scenario (attack or fortify): " << endl;
    string scenario = "";
    cin >> scenario;

    //Create 2 players, but FOO is the one being observed
    Player *FOO = new Player(1, "Foo", "blue");
    Player *BAR = new Player(2,"bar","blue");
    GameView *gameView = new GameView(FOO);

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


    return 0;
}

