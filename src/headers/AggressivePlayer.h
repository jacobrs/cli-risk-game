#ifndef AGGRESSIVEPLAYER_H
#define AGGRESSIVEPLAYER_H

#include "Strategy.h"
#include "Player.h"
#include "GameMap.h"
using namespace std;

class AggressivePlayer: public Strategy{
public:
    void execute(Player*, GameMap*);
    ~AggressivePlayer();
};

#endif