#include "../headers/CheaterPlayer.h"
#include <iostream>

using namespace std;
void CheaterPlayer::execute(Player *player, GameMap *map){
    cout<<"Cheater Player is playing"<<endl;
    player->reinforce(map);
    player->attack(map);
    //for loop over all counties that have an oponnent as a neigbour
    //armies to move = 2*countries neighboring opponent
    //ignore the country to move armies from, this is a cheating strategy
    for(int i = 0; i < map->numberOfContinents; i++){
        for(int j = 0; j < map->continents[i]->numberOfCountries; j++){
            Country* country = map->continents[i]->countries[j];
            if(country->hasEnnemies()){
                player->fortify(NULL, country, (country->armies)*2);
            }
        }
    }
}
CheaterPlayer::~CheaterPlayer(){}