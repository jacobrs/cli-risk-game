#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Subject.h"
#include "Player.h"

#include <string>

using namespace std;

class GamePlay : public Subject{

public:
    GamePlay();
    ~GamePlay();
    void start(string phase);

private:
    string phase;
};

#endif
