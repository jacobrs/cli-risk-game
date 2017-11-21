#include "../headers/CheaterPlayer.h"
#include <iostream>

using namespace std;
void CheaterPlayer::execute(Player *player, GameMap *map){
    cout<<"Cheater Player is playing"<<endl;
    player->reinforce(map);
    player->attack(map);

    string strongest = player->getStrongetAttackCountry(map);
    string weakest = player->getWeaketCountry(map);

    Country* weakestCountry = map->getCountryByName(weakest);
    Country* strongestCountry = map->getCountryByName(strongest);
    if(weakestCountry != NULL && strongestCountry != NULL)
        player->fortify(weakestCountry, strongestCountry, weakestCountry->armies);
    else cout<< "Error finding countries for fortification"<< endl; 
}
CheaterPlayer::~CheaterPlayer(){}