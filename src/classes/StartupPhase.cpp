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

StartupPhase::StartupPhase(GameMap* map, int numPlayers){

    //Creation of players
    nbPlayers = numPlayers;
    vector <Player> listPlayers(nbPlayers);
    createPlayer(numPlayers);
    shufflePlayers();
    
    //Randomizing countries and assigning them an owner

    for (int i=0; i < map->numberOfContinents; i++)
    {
        for (int j = 0; j < map->continents[i]->numberOfCountries; j++)
        {
            cout << map-> continents[i] -> countries[j]->name << endl;
            cout << "loop1" <<endl;
        }
        cout << "loop2"<<endl;
    }

    cout << "done";

    printMapWithOwner();
    
    //Starting amount of armies varies depending on amount of players
    switch (numPlayers){
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

void StartupPhase::shuffleCountries(){
    
}

//show country and respective its owner
void StartupPhase::printMapWithOwner(){

}
