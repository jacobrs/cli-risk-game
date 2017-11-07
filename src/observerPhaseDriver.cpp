#include "headers/GameView.h"
#include "headers/GamePlay.h"
#include "headers/Player.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

    //Create a GamePlay to be observed
    GamePlay* gp = new GamePlay;

    //Create a GameView that is connected to the GamePlay
    GameView *gameview1 = new GameView(gp);

    string phasePlay;

    cout << "Enter a game Phase";
    cin >> phasePlay;

    gp->start(phasePlay);

    return 0;
}