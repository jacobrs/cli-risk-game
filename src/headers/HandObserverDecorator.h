#ifndef HANDOBSERVER_H
#define HANDOBSERVER_H

#include "GameMap.h"
#include "Observer.h"
#include "Player.h"
#include <string>
#include <vector>
#include "./GameStateObserver.h"

class GameMap;
class Observer;
class GameStateObserver;

class HandObserverDecorator: public GameStateObserver {

  private:
    GameStateObserver* gameStateObserver;

  public:
    HandObserverDecorator(GameStateObserver* observer);
    ~HandObserverDecorator();
    void updateState(GameMap*, vector<Player*>);

};

#endif
