#include "../headers/ContinentObserverDecorator.h"
#include "../headers/GameMap.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

ContinentObserverDecorator::ContinentObserverDecorator(GameStateObserver* observer){
  gameStateObserver = observer;
}

ContinentObserverDecorator::~ContinentObserverDecorator(){
  delete gameStateObserver;
}

void ContinentObserverDecorator::updateState(GameMap* map, vector<Player*> players){

  const int LINE_LENGTH = 40;

  string CYAN = "\x1b[1;36m";
  string DEFAULT = "\x1b[0m";

  printf("%s========== CONTINENT STATE =============%s\n", CYAN.c_str(), DEFAULT.c_str());
  printf("%s|                                       %s\n", CYAN.c_str(), DEFAULT.c_str());
  for(int i = 0; i < map->numberOfContinents; i++){
    string contender = map->continents[i]->countries[0]->owner->name;
    for(int j = 0; j < map->continents[i]->numberOfCountries; j++){
      if(map->continents[i]->countries[j]->owner->name != contender){
        contender = "Contested";
        break;
      }
    }
    
    printf("%s|%s %s : %s\n", CYAN.c_str(), DEFAULT.c_str(),  map->continents[i]->name.c_str(), contender.c_str());
  }
  printf("%s|                                       %s\n", CYAN.c_str(), DEFAULT.c_str());
  printf("%s========================================%s\n", CYAN.c_str(), DEFAULT.c_str());

}
