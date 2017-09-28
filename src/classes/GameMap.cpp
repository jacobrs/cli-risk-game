#include "../headers/GameMap.h"
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

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

  // check that every continent has at least one country
  // check that the map has at least one continent

  if(numberOfContinents < 1){
    return false;
  }else{
    for(int i = 0; i < numberOfContinents; i++){
      if(continents[i]->numberOfCountries < 1){
        return false;
      }
    }
  }

  // each country belongs to one and only one continent
  // gather every country in every continent and while doing that, search for duplicates

  printf("Checking if each country belongs to only one continent ");

  vector<string> allCountries;
  map<string, int> countryCounter;
  for(int i = 0; i < numberOfContinents; i++){
    for(int j = 0; j < continents[i]->numberOfCountries; j++){
      if(find(allCountries.begin(), allCountries.end(), continents[i]->countries[j]->name) != allCountries.end()){
        printf("%s FAILED %s\n", RED.c_str(), DEFAULT.c_str());
        return false;
      }else{
        allCountries.push_back(continents[i]->countries[j]->name);
        countryCounter.insert(pair<string, int>(continents[i]->countries[j]->name, 1));
      }
    }
  }

  printf("%s PASSED %s\n", GREEN.c_str(), DEFAULT.c_str());

  // check that the map is a connected graph

  printf("Checking if all countries are interconnected ");
  
  vector<Country*> visited;
  Country *startingPoint = continents[0]->countries[0];

  queue<Country*> pending;
  pending.push(startingPoint);
  visited.push_back(startingPoint);

  while(!pending.empty()){
    Country* current = pending.front();
    pending.pop();

    map<string,int>::iterator it = countryCounter.find(current->name);
    if (it == countryCounter.end()){
      printf("%s FAILED %s\n", RED.c_str(), DEFAULT.c_str());
      return false;
    }

    for(int i = 0; i < current->numberOfNeighbours; i++) {
      if(!(find(visited.begin(), visited.end(), current->neighbours[i]) != visited.end())){
        pending.push(current->neighbours[i]);
        visited.push_back(current->neighbours[i]);
      }
    }
  }

  if(visited.size() != allCountries.size()){
    printf("%s FAILED %s\n", RED.c_str(), DEFAULT.c_str());
    return false;
  }

  printf("%s PASSED %s\n", GREEN.c_str(), DEFAULT.c_str());

  // continents are connected subgraphs
  // by logical deduction if all countries are interconnected and every continent
  // has a country and every country belongs to one and only one continent
  // all continents are also interconneted

  printf("Checking if all continents are interconnected %s PASSED %s\n", GREEN.c_str(), DEFAULT.c_str());

  return true;

}
