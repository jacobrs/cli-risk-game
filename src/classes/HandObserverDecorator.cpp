#include "../headers/HandObserverDecorator.h"
#include "../headers/GameMap.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

HandObserverDecorator::HandObserverDecorator(GameStateObserver* observer){
  gameStateObserver = observer;
}

HandObserverDecorator::~HandObserverDecorator(){
  delete gameStateObserver;
}

void HandObserverDecorator::updateState(GameMap* map, vector<Player*> players){

  string CYAN = "\x1b[1;36m";
  string DEFAULT = "\x1b[0m";

  printf("%s============ HAND STATE ================%s\n", CYAN.c_str(), DEFAULT.c_str());
  printf("%s|                                       %s\n", CYAN.c_str(), DEFAULT.c_str());
  for (auto &player : players){
    printf("%s|%s %s's hand\n", CYAN.c_str(), DEFAULT.c_str(), player->name.c_str());
    player->hand->printHand();
  }
  printf("%s========================================%s\n", CYAN.c_str(), DEFAULT.c_str());

}
