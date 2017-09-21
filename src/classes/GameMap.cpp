#include "../headers/GameMap.h"

using namespace std;

GameMap::GameMap(){
  numberOfContinents = 0;
}

void GameMap::addContinent(Continent* newContinent){
  
  bool alreadyElement = false;

  // Create a new array of size current + 1
  Continent **newContinents = new Continent*[++numberOfContinents];
  // and populate it with the old continents
  for(int i = 0; i < numberOfContinents - 1; i++){
    newContinents[i] = continents[i];
    if(continents[i]->name == newContinent->name){
      alreadyElement = true;
      break;
    }
  }

  // add the new neighbour to the list if not already neighbours
  if(!alreadyElement){
    newContinents[numberOfContinents - 1] = newContinent;
    // and make sure that the new neighbour knows its a neighbour    
    continents = newContinents;
  }else{
    numberOfContinents--;
  }

}
