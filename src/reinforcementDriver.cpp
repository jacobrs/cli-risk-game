#include <iostream>
#include "./headers/Player.h"
#include "./headers/GameMap.h"
#include "./headers/MapLoader.h"
#include "./headers/Deck.h"

using namespace std;

int main(int args, char** argv){
  
  // Initialize a new game with a valid map
  Country* canada = new Country("Canada");
  Country* usa = new Country("USA");
  Country* mexico = new Country("Mexico");
  Country* venezuela = new Country("Venezuela");
  Country* brazil = new Country("Brazil");
  Country* argentina = new Country("Argentina");
  Country* chile = new Country("Chile");
  Country* cuba = new Country("Cuba");

  canada->armies = 1;
  usa->armies = 1;
  mexico->armies = 1;
  venezuela->armies = 1;
  brazil->armies = 1;
  argentina->armies = 1;
  chile->armies = 1;
  cuba->armies = 1;

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

  GameMap* map = new GameMap();
  map->addContinent(northAmerica);
  map->addContinent(southAmerica);

  cuba->addNeighbour(mexico);
  brazil->addNeighbour(chile);
  chile->addNeighbour(venezuela);
  chile->addNeighbour(argentina);
  southAmerica->addCountry(cuba);

  Player* foo = new Player(0, "foo", "red");
  Player* bar = new Player(1, "bar", "blue");

  canada->owner = foo;
  usa->owner = foo;
  mexico->owner = foo;
  venezuela->owner = foo;

  chile->owner = bar;
  brazil->owner = bar;
  cuba->owner = bar;
  argentina->owner = bar;

  Deck* deck = new Deck(8);
  deck->shuffleDeck();

  // verify that the map was loaded in properly
  printf("Checking integrity of game map\n\n");
  map->isValidMap();

  printf("Starting reinforcement phase\n");

  // foo owns north america
  foo->reinforce(map);
  bar->reinforce(map);

  bar->hand->addCard(deck->draw());
  bar->hand->addCard(deck->draw());
  bar->hand->addCard(deck->draw());
  bar->hand->addCard(deck->draw());
  bar->hand->addCard(deck->draw());
  bar->hand->addCard(deck->draw());

  foo->reinforce(map);
  bar->reinforce(map);

  delete map;
  delete foo;
  delete bar;
  delete deck;

}
