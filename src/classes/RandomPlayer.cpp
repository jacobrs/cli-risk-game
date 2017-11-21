#include "../headers/RandomPlayer.h"
#include <iostream>

using namespace std;

void RandomPlayer::execute(Player *player, GameMap* map){
    cout<<"Random player playing"<< endl;
    player->reinforce(map);
    player->attack(map);

    //fortifies the random country by moving a random number of armies from another random country
    string country1 = player->getRandomCountry(map);
    string country2 = player->getRandomCountry(map);
    while (country1 == country2){
        country2 = player->getRandomCountry(map);
    }
    Country* coun1 = map->getCountryByName(country1);
    Country* coun2 = map->getCountryByName(country2);
    if(coun1 != NULL && coun2 != NULL)
        player->fortify(coun1, coun1, (rand()% coun1->armies) + 1);
    else cout<< "Error finding countries for fortification"<< endl; 
}
RandomPlayer::~RandomPlayer(){}