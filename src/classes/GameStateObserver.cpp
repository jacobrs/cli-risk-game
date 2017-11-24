#include "../headers/GameStateObserver.h"
#include "../headers/GameMap.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

void GameStateObserver::updateState(GameMap* map, vector<Player*> players){

  const int LINE_LENGTH = 40;

  string CYAN = "\x1b[1;36m";
  string DEFAULT = "\x1b[0m";

  std::map<const char*, int> playerCountries;
  std::map<const char*, int> playerArmies;
  for (auto &player : players)
  {  
      playerCountries.insert(std::pair<const char*, int>(player->name.c_str(), 0));
      playerArmies.insert(std::pair<const char*, int>(player->name.c_str(), 0));
  }

  double totalCountries = 0;

  for(int i = 0; i < map->numberOfContinents; i++){
    for(int j = 0; j < map->continents[i]->numberOfCountries; j++){
      int n_c = playerCountries.at(map->continents[i]->countries[j]->owner->name.c_str()) + 1;
      playerCountries[map->continents[i]->countries[j]->owner->name.c_str()] = n_c;
      n_c = playerArmies.at(map->continents[i]->countries[j]->owner->name.c_str()) + map->continents[i]->countries[j]->armies;
      playerArmies[map->continents[i]->countries[j]->owner->name.c_str()] = n_c;
      totalCountries += 1;
    }
  }

  printf("\n\n%s============ BASIC STATE ================%s\n", CYAN.c_str(), DEFAULT.c_str());
  printf("%s|                                       %s\n", CYAN.c_str(), DEFAULT.c_str());
  for (auto &player : players)
  {
    printf("%s|%s %s has %d countries\n", CYAN.c_str(), DEFAULT.c_str(), player->name.c_str(), playerCountries.at(player->name.c_str()));
    printf("%s|%s and %d armies\n", CYAN.c_str(), DEFAULT.c_str(), playerArmies.at(player->name.c_str()));
    printf("%s|                                       %s\n", CYAN.c_str(), DEFAULT.c_str());
  }
  printf("%s========================================%s\n", CYAN.c_str(), DEFAULT.c_str());

}

void GameStateObserver::update(){
  //stub
}

void GameStateObserver::updateAttack(int a, string attackName, string defendName, int aa, int da, bool conquered){
  //stub
}

void GameStateObserver::updateReinforce(int r, int p, string where){
  //stub
}

void GameStateObserver::updateFortify(int f, string a, string b, int m){
  //stub
}
