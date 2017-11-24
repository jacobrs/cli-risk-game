#ifndef CHEATERPLAYER_H
#define CHEATERPLAYER_H

#include "Strategy.h"
#include "Player.h"
#include "GameMap.h"

using namespace std;

class CheaterPlayer: public Strategy{
    public: 
        void execute(Player*, GameMap*);
        ~CheaterPlayer();
};

#endif