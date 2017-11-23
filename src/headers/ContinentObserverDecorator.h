#ifndef CONTINENTOBSERVER_H
#define CONTINENTOBSERVER_H

#include "GameMap.h"
#include "Observer.h"
#include "Player.h"
#include <string>
#include <vector>
#include "./GameStateObserver.h"

class GameMap;
class Observer;
class GameStateObserver;

class ContinentObserverDecorator: public GameStateObserver {

  private:
    GameStateObserver* gameStateObserver;

  public:
    ContinentObserverDecorator(GameStateObserver* observer);
    ~ContinentObserverDecorator();
    void updateState(GameMap*, vector<Player*>);

};

#endif
