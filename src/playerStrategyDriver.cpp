#include "headers/Player.h"
#include "headers/Country.h"
#include "headers/Continent.h"
#include "headers/GameMap.h"
#include "headers/HumanPlayer.h"
#include "headers/AggressivePlayer.h"
#include "headers/BenevolentPlayer.h"

using namespace std;

int main(int args, char** argv){

  srand (time(NULL)); 
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
  
  HumanPlayer *humanPlayer = new HumanPlayer();
  Player *player1 = new Player(humanPlayer);

  AggressivePlayer *aggressivePlayer = new AggressivePlayer();
  Player *player2 = new Player(aggressivePlayer);
  
  canada->armies=10;
  canada->owner=player1;
  mexico->armies=10;
  mexico->owner=player1;
  usa->armies=2;
  usa->owner=player2;

  player1->executeStrategy(map);
  player2->executeStrategy(map);

  delete humanPlayer;
  delete aggressivePlayer;

  delete player1;
  delete player2;

  return 0;
}