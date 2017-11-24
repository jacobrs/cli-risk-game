#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "Strategy.h"
#include "Player.h"
#include "GameMap.h"
using namespace std;

class RandomPlayer: public Strategy{
public:
    void execute(Player*, GameMap*);
    ~RandomPlayer();
};

#endif