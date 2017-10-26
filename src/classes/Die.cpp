#include "../headers/Die.h"

using namespace std;

Die::Die(){
    dieSide = 1;
}

void Die::rollDie(){
    dieSide = rand()%6 + 1;
}
