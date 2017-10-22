#include "../headers/Country.h"

using namespace std;

Country::Country(string countryName){
  armies = 0;
  name = countryName;
  numberOfNeighbours = 0;
}

Country::Country(){
  armies = 0;
  name = "";
  numberOfNeighbours = 0;
}

bool Country::isNeighbour(Country* c){
  for(int i = 0; i < numberOfNeighbours; i++){
    if(neighbours[i]->name == c->name){
      return true;
    }
  }
  return false;
}

void Country::addNeighbour(Country* newNeighbour){

  bool alreadyNeighbours = false;

  // Create a new array of size current + 1
  Country **newNeighbours = new Country*[++numberOfNeighbours];
  // and populate it with the old neighbours
  for(int i = 0; i < numberOfNeighbours - 1; i++){
    newNeighbours[i] = neighbours[i];
    if(neighbours[i]->name == newNeighbour->name){
      alreadyNeighbours = true;
      break;
    }
  }

  // add the new neighbour to the list if not already neighbours
  if(!alreadyNeighbours){
    newNeighbours[numberOfNeighbours - 1] = newNeighbour;
    // and make sure that the new neighbour knows its a neighbour
    neighbours = newNeighbours;
    newNeighbour->addNeighbour(this);
  }else{
    numberOfNeighbours--;
  }

}
