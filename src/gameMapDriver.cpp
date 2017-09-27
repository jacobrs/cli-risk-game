#include "headers/Player.h"
#include "headers/Country.h"
#include "headers/Continent.h"
#include "headers/GameMap.h"

using namespace std;

int main(int args, char** argv){

  // temporary testing code
  Country* canada = new Country("Canada");
  Country* usa = new Country("USA");
  Country* mexico = new Country("Mexico");
  Country* venezuela = new Country("Venezuela");
  Country* brazil = new Country("Brazil");
  Country* argentina = new Country("Argentina");

  usa->addNeighbour(canada);
  usa->addNeighbour(mexico);

  brazil->addNeighbour(argentina);
  brazil->addNeighbour(venezuela);

  // link continents together
  venezuela->addNeighbour(mexico);

  Continent* northAmerica = new Continent("North America", 5);
  Continent* southAmerica = new Continent("South America", 2);
  
  northAmerica->addCountry(canada);
  northAmerica->addCountry(usa);
  northAmerica->addCountry(mexico);

  southAmerica->addCountry(venezuela);
  southAmerica->addCountry(brazil);
  southAmerica->addCountry(argentina);

  GameMap map = GameMap();
  map.addContinent(northAmerica);
  map.addContinent(southAmerica);

  map.isValidMap();

  northAmerica->addCountry(brazil);

}
