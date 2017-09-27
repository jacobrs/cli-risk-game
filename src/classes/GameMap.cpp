#include "../headers/GameMap.h"
#include <algorithm>
#include <vector>
#include <string>

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

bool GameMap::isValidMap(){

  string RED = "\x1b[31m";
  string GREEN = "\x1b[32m";
  string DEFAULT = "\x1b[0m";

  // check that the map is a connected graph

  // continents are connected subgraphs

  // each country belongs to one and only one continent
  // gather every country in every continent and while doing that, search for duplicates

  printf("Checking if each country belongs to one and only one continent ");

  vector<string> allCountries;
  for(int i = 0; i < numberOfContinents; i++){
    for(int j = 0; j < continents[i]->numberOfCountries; j++){
      if(find(allCountries.begin(), allCountries.end(), continents[i]->countries[j]->name) != allCountries.end()){
        printf("%s FAILED %s\n", RED.c_str(), DEFAULT.c_str());
        return false;
      }else{
        allCountries.push_back(continents[i]->countries[j]->name);
      }
    }
  }

  printf("%s PASSED %s\n", GREEN.c_str(), DEFAULT.c_str());

  return true;

}
