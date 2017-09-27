#include "../headers/Die.h"

using namespace std;

Die::Die(){
    dieSide = 0;
}

int Die::rollDie(){
    dieSide = rand()%6 + 1;
    return dieSide;
}