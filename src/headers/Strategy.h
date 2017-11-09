#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include "Player.h"
#include "GameMap.h"

using namespace std;

class Player;
class GameMap;

class Strategy{
public: 
    virtual void execute(Player*, GameMap*) = 0;
    virtual ~Strategy(){}
};
#endif 