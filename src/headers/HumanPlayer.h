#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Strategy.h"
#include "Player.h"
#include "GameMap.h"
using namespace std;

class HumanPlayer: public Strategy{
public: 
    void execute(Player*, GameMap*);
    ~HumanPlayer();
};

#endif