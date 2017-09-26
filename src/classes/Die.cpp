#include "../headers/Die.h"
/*#include <stdlib.h>
#include <time.h>
#include <iostream>*/

using namespace std;

Die::Die(){
    dieSide = 0;
}

int Die::rollDie(){
    dieSide = rand()%6 + 1;
    return dieSide;
}