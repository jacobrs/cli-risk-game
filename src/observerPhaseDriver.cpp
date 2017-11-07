#include "headers/GameView.h"
#include "headers/Player.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

    //Create a GamePlay to be observed
    Player* p = new Player;

    //Create a GameView that is connected to the GamePlay
    GameView *gameview1 = new GameView(p);



    return 0;
}