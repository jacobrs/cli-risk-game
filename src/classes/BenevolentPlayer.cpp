#include "../headers/BenevolentPlayer.h"
#include <iostream>

using namespace std;

void BenevolentPlayer::execute(Player *player, GameMap* map){
    cout<< "Benevolent Player"<< endl;
    player->reinforce(map);
    //this player never attacks
    //player->attack(map);
    //player->fortify();
}
BenevolentPlayer::~BenevolentPlayer(){}