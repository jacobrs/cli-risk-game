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
  Country* chile = new Country("Chile");
  Country* cuba = new Country("Cuba");

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
  southAmerica->addCountry(chile);
  southAmerica->addCountry(argentina);

  GameMap map = GameMap();
  map.addContinent(northAmerica);
  map.addContinent(southAmerica);

  printf("Testing while chile is not connected [SHOULD FAIL]\n===========================\n");

  map.isValidMap();
  printf("\n");

  printf("Testing while chile is not connected and cuba is [SHOULD FAIL]\n===========================\n");
  
  cuba->addNeighbour(mexico);

  map.isValidMap();
  printf("\n");

  printf("Adding chile's neighbours and adding cuba to south america and retesting [SHOULD PASS]\n===========================\n");
  brazil->addNeighbour(chile);
  chile->addNeighbour(venezuela);
  chile->addNeighbour(argentina);
  southAmerica->addCountry(cuba);

  map.isValidMap();
  printf("\n");

  printf("Adding chile to north america and retesting [SHOULD FAIL]\n===========================\n");
  northAmerica->addCountry(chile);

  map.isValidMap();
  printf("\n");

  delete chile;
  delete usa;
  delete canada;
  delete mexico;
  delete venezuela;
  delete brazil;
  delete argentina;

  delete northAmerica;
  delete southAmerica;
  
}
