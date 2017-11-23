#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H

#include "GameMap.h"
#include "Observer.h"
#include "Player.h"
#include <string>
#include <vector>
#include "./GameStateObserver.h"

class GameMap;
class Observer;
class GameStateObserver;

class CountryObserverDecorator: public GameStateObserver {

  private:
    GameStateObserver* gameStateObserver;

  public:
    CountryObserverDecorator(GameStateObserver* observer);
    ~CountryObserverDecorator();
    void updateState(GameMap*, vector<Player*>);

};

#endif
