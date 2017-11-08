#include "../headers/AggressivePlayer.h"
#include <iostream>

using namespace std;

void AggressivePlayer::execute(Player *player, GameMap* map){
    cout<<"Agressive player playing"<< endl;
    player->reinforce(map);
    player->attack(map);

    //fortifies the countries with the most armies by moving the armies from the weakest contries to the strongest ones
    string strongest = player->getStrongetCountry(map);
    string weakest = player->getWeaketCountry(map);

    Country* weakestCountry = map->getCountryByName(weakest);
    Country* strongestCountry = map->getCountryByName(strongest);
    if(weakestCountry != NULL && strongestCountry != NULL)
        player->fortify(weakestCountry, strongestCountry, weakestCountry->armies);
    else cout<< "Error finding countries for fortification"<< endl; 
}
AggressivePlayer::~AggressivePlayer(){}
