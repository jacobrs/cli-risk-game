#include "headers/Player.h"
#include "headers/Country.h"
#include "headers/Continent.h"
#include "headers/GameMap.h"
#include "headers/Die.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int args, char** argv){

  // Instantiation of game object goes here.

  // temporary testing code
  
  Country* canada = new Country("Canada");
  Country* usa = new Country("USA");
  Country* mexico = new Country("Mexico");

  usa->addNeighbour(canada);
  usa->addNeighbour(mexico);

  Player* player1 = new Player(0, "Jacob", "red");

  usa->owner = player1;

  printf("%s == Jacob\n", usa->owner->name.c_str());
  printf("%s == Canada\n", usa->neighbours[0]->name.c_str());
  printf("%s == Mexico\n", usa->neighbours[1]->name.c_str());

  printf("%i == 1\n", canada->numberOfNeighbours);
  printf("%s == USA\n", canada->neighbours[0]->name.c_str());
  printf("%s == Jacob\n", canada->neighbours[0]->owner->name.c_str());

  Continent* northAmerica = new Continent("North America", 5);
  northAmerica->addCountry(canada);
  northAmerica->addCountry(usa);
  northAmerica->addCountry(mexico);

  printf("\nCountries part of %s\n", northAmerica->name.c_str());

  for(int i = 0; i < northAmerica->numberOfCountries; i ++){
    printf("%s\n", northAmerica->countries[i]->name.c_str());
  }

  GameMap map = GameMap();
  map.addContinent(northAmerica);

  printf("\nContinents part of GameMap\n");
  
  for(int i = 0; i < map.numberOfContinents; i ++){
    printf("%s\n", map.continents[i]->name.c_str());
  }
  srand (time(NULL));
  Die die1 = Die();
  die1.rollDie();

  Die die2 = Die();
  die2.rollDie();

  Die die3 = Die();
  die3.rollDie();

  printf("\ndie 1 rolls %d", die1.dieSide, "\n");
  printf("\ndie 2 rolls %d", die2.dieSide, "\n");
  printf("\ndie 3 rolls %d", die3.dieSide, "\n");

  die1.rollDie();
  die2.rollDie();
  die3.rollDie();

  printf("\ndie 1 rolls again %d", die1.dieSide, "\n");
  printf("\ndie 2 rolls again %d", die2.dieSide, "\n");
  printf("\ndie 3 rolls again %d", die3.dieSide, "\n");
}
