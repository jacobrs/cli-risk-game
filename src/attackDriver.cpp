#include "headers/Player.h"
#include "headers/Country.h"
#include "headers/Continent.h"
#include "headers/GameMap.h"

using namespace std;

int main(int args, char** argv){

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

  GameMap map = GameMap();
  map.addContinent(northAmerica);
  map.addContinent(southAmerica);

  map.isValidMap();

  Player* FOO = new Player(1,"foo","red",3);
  Player* BAR = new Player(2,"bar","blue",3);

  canada->armies=1;
  canada->owner=FOO;
  mexico->armies=1;
  mexico->owner=FOO;
  usa->armies=1;
  usa->owner=BAR;

  
}
