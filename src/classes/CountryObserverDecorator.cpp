#include "../headers/CountryObserverDecorator.h"
#include "../headers/GameMap.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

CountryObserverDecorator::CountryObserverDecorator(GameStateObserver* observer){
  gameStateObserver = observer;
}

CountryObserverDecorator::~CountryObserverDecorator(){
  delete gameStateObserver;
}

string generateBar(double percent){
  const int ratio = 36;
  string bar = "";
  string GREEN = "\x1b[32m";
  string DEFAULT = "\x1b[0m";

  for(int i = 0; i < ratio * percent ; i++ ){
    bar += "+";
  }
  for(int j = ratio; j > (ratio * percent) + 1; j--){
    bar += " ";
  }
  return GREEN + bar + DEFAULT;
}

void CountryObserverDecorator::updateState(GameMap* map, vector<Player*> players){

  const int LINE_LENGTH = 40;

  string CYAN = "\x1b[1;36m";
  string DEFAULT = "\x1b[0m";

  std::map<const char*, int> playerCountries;
  std::map<const char*, int> playerArmies;
  for (auto &player : players){  
      playerCountries.insert(std::pair<const char*, int>(player->name.c_str(), 0));
      playerArmies.insert(std::pair<const char*, int>(player->name.c_str(), 0));
  }

  double totalCountries = 0;

  for(int i = 0; i < map->numberOfContinents; i++){
    for(int j = 0; j < map->continents[i]->numberOfCountries; j++){
      int n_c = playerCountries.at(map->continents[i]->countries[j]->owner->name.c_str()) + 1;
      playerCountries[map->continents[i]->countries[j]->owner->name.c_str()] = n_c;
      totalCountries += 1;
    }
  }

  printf("%s========== DOMINATION STATE ============%s\n", CYAN.c_str(), DEFAULT.c_str());
  printf("%s|                                       %s\n", CYAN.c_str(), DEFAULT.c_str());
  for (auto &player : players){
    printf("%s|%s %s\n", CYAN.c_str(), DEFAULT.c_str(), player->name.c_str());
    printf("%s|%s %s \n", CYAN.c_str(), DEFAULT.c_str(), generateBar(playerCountries.at(player->name.c_str()) / totalCountries).c_str());
  }
  printf("%s========================================%s\n", CYAN.c_str(), DEFAULT.c_str());

}
