#include "headers/Player.h"
#include "headers/Country.h"

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

}
