#include "../headers/StartupPhase.h"
#include "../headers/MapLoader.h"
#include "../headers/GameMap.h"
#include "../headers/Player.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

StartupPhase::StartupPhase(){
    nbPlayers = 0;
}

StartupPhase::StartupPhase(GameMap* map, vector<Player*> players){

    //Creation of players
    nbPlayers = players.size();
    //createPlayer(nbPlayers);
    listPlayers = players;

    //Randomizing countries and assigning them an owner

    int playerCtr = 0;
    for (int i=0; i < map->numberOfContinents; i++)
    {
        for (int j = 0; j < map->continents[i]->numberOfCountries; j++)
        {
            cout << map-> continents[i] -> countries[j]->name << endl;
            map-> continents[i] -> countries[j]->owner = this->listPlayers[playerCtr];
            playerCtr = (playerCtr + 1) % (nbPlayers);
            cout << map-> continents[i] -> countries[j]->owner -> name << endl;
        }
    }

    //printMapWithOwner();

    //Starting amount of armies varies depending on amount of players
    switch (nbPlayers){
        case(2):
            armiesStart = 40;
            break;
        case(3):
            armiesStart = 35;
            break;
        case(4):
            armiesStart = 30;
        break;
        case(5):
            armiesStart = 25;
            break;
        case(6):
            armiesStart = 20;
            break;
        default:
            cout << "Wrong number of players" <<endl;
            break;
    }

    for (int k = 0; k < nbPlayers; k ++)
    {
        int pieceCtr = armiesStart;
        while (pieceCtr > 0)
        {
            for (int i=0; i < map->numberOfContinents; i++)
            {
                for (int j = 0; j < map->continents[i]->numberOfCountries; j++)
                {
                    if (map-> continents[i] -> countries[j]->owner->name == this->listPlayers[k]->name)
                    {
                        map-> continents[i] -> countries[j]->armies ++;
                        cout << "Player " << map-> continents[i] -> countries[j]->owner->name << " placed a token on "<<map-> continents[i] -> countries[j]->name << " and now has "<< map-> continents[i] -> countries[j]->armies << " tokens " << endl;
                        
                        pieceCtr --;
                    }
                        
                }
            }
        }
    }


}
//randomizing the order of the players
void StartupPhase::shufflePlayers(){
    random_device rd;
    mt19937 g(rd());

	shuffle(listPlayers.begin(), listPlayers.end(), g);
}

void StartupPhase::createPlayer(int nbPlayers){
        
        //creates the different players
        for (int i = 0; i < nbPlayers; i++)
        {
                string playerName = "";
                string playerColour = "";
                cout << "Player name: ";
                cin >> playerName;
 
                Player* newPlayer = new Player(i, playerName, playerColour);
                this -> listPlayers.push_back(newPlayer);
        }
}

