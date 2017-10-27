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
  cuba->addNeighbour(mexico);
  brazil->addNeighbour(argentina);
  brazil->addNeighbour(venezuela);
  brazil->addNeighbour(chile);
  chile->addNeighbour(venezuela);
  chile->addNeighbour(argentina);

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
  southAmerica->addCountry(cuba);

  GameMap map = GameMap();
  map.addContinent(northAmerica);
  map.addContinent(southAmerica);

  map.isValidMap();

  Player* FOO = new Player(1,"foo","red");
  Player* BAR = new Player(2,"bar","blue");

  canada->armies=1;
  canada->owner=FOO;
  mexico->armies=1;
  mexico->owner=FOO;
  usa->armies=1;
  usa->owner=BAR;

  printf("\nMoving canada army to mexico: [SHOULD FAIL] (not neighbours)\n");
  FOO->fortify(canada,mexico,1) ? printf("PASS\n") : printf("FAIL\n");

  printf("\nMoving canada army to usa: [SHOULD FAIL] (don't belong to same player)\n");
  FOO->fortify(canada,usa,1) ? printf("PASS\n") : printf("FAIL\n");

  usa->owner=FOO;
  printf("\nMoving canada army to usa: [SHOULD FAIL] (armiesToMove == 0)\n");
  FOO->fortify(canada,usa,0) ? printf("PASS\n") : printf("FAIL\n");

  printf("\nMoving canada army to usa: [SHOULD FAIL] (armiesToMove >= canada's army)\n");
  FOO->fortify(canada,usa,50) ? printf("PASS\n") : printf("FAIL\n");

  canada->armies = 51;
  cout << "\nCanada's army BEFORE move: " << canada->armies << endl << "USA's army BEFORE move: " << usa->armies;
  printf("\nMoving 50 canadian army to usa: [SHOULD PASS]\n");
  FOO->fortify(canada,usa,50) ? printf("PASS\n") : printf("FAIL\n");
  cout << "Canada's army AFTER move: " << canada->armies << endl << "USA's army AFTER move: " << usa->armies << endl;
}
