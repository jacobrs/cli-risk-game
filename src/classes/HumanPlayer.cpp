#include "../headers/HumanPlayer.h"
#include <iostream>

using namespace std;

void HumanPlayer::execute(Player *player, GameMap* map){
    cout<< "Human Player"<< endl;
    player->attack(map);
}
HumanPlayer::~HumanPlayer(){}