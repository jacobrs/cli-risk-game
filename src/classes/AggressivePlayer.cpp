#include "../headers/AggressivePlayer.h"
#include <iostream>

using namespace std;

void AggressivePlayer::execute(Player *player, GameMap* map){
    cout<<"Agressive player playing"<< endl;
    player->attack(map);
}
AggressivePlayer::~AggressivePlayer(){}