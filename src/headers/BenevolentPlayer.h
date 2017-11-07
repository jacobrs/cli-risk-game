#ifndef BENEVOLENTPLAYER_H
#define BENEVOLENTPLAYER_H

#include <string>
#include "Strategy.h"
#include "Player.h"
#include "GameMap.h"
using namespace std;

class BenevolentPlayer : public Strategy{
public: 
    void execute(Player*, GameMap*);
    ~BenevolentPlayer();
};

#endif