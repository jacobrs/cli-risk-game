#include "headers/StartupPhase.h"
#include "headers/MapLoader.h"
#include "headers/Player.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){

  // Initialize a new game with a valid map
  MapLoader* loader = new MapLoader("./src/map/World.map");
  loader->importMap();
  GameMap* map = loader->exportToGameMap();

  // verify that the map was loaded in properly
  printf("Checking integrity of game map\n\n");
  map->isValidMap();

    int numOfPlayers = 0;

    vector <Player> players;
       
        cout << "Number of Players between 2-6: " << endl;
        cin >> numOfPlayers;

        StartupPhase* startGame = new StartupPhase(map, numOfPlayers);
   
    return 0;
}
