#ifndef DIE_H
#define DIE_H

#include "Die.h"
#include <random>
#include <time.h>
#include <string>

using namespace std;

class Die{
public:
    int dieSide;

    Die();
    void rollDie();
};

#endif
