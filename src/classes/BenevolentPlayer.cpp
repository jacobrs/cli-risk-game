#include "../headers/BenevolentPlayer.h"
#include <iostream>

using namespace std;

void BenevolentPlayer::execute(Player *player, GameMap* map){
    cout<< "Benevolent Player"<< endl;
    player->reinforce(map);
    //this player never attacks
    player->attack(map);

    //moves armies from strong countries to weak ones to fortify them
    string strongest = player->getStrongetCountry(map);
    string weakest = player->getWeaketCountry(map);

    Country* weakestCountry = map->getCountryByName(weakest);
    Country* strongestCountry = map->getCountryByName(strongest);
    if(weakestCountry != NULL && strongestCountry != NULL)
        player->fortify(strongestCountry, weakestCountry, strongestCountry->armies);
    else cout<< "Error finding countries for fortification"<< endl; 
}
BenevolentPlayer::~BenevolentPlayer(){}