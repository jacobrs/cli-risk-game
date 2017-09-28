#ifndef DIE_H
#define DIE_H

#include "Die.h"
#include <string>

using namespace std;

class Die{
public:
    int dieSide;

    Die();
    int rollDie();
};

#endif