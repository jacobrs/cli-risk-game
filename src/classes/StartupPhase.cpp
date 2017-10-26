#include "../headers/StartupPhase.h"
#include "../headers/MapLoader.h"
#include "../headers/GameMap.h"
#include "../headers/Player.h"
#include <string>
#include <vector>

using namespace std;

StartupPhase::StartupPhase2(){
}

StartupPhase::StartupPhase2(string mapPlaying, int numPlayers){
    map = mapPlaying;
    nbPlayers = numPlayers;

    createPlayer(numPlayers);
    shufflePlayers();
    
    switch (numPlayers){
        case(2):
            armies = 40;
            break;
        case(3):
            armies = 35;
            break;
        case(4):
            armies = 30;
        break;
        case(5):
            armies = 25;
            break;
        case(6):
            armies = 20;
            break;
        default:
            break;
    }



}

void StartupPhase::shufflePlayers(){
    random_device rd;
    mt19937 g(rd());

	shuffle(players.begin(), players.end(), g);
}

void StartupPhase::createPlayer(){
    
    players.reserve(nbPlayers);
    
        //creates the different players
        for (int i = 0; i < nbPlayers; i++)
        {
                string playerName = "";
                string playerColour = "";
                cout << "Player name: ";
                cin >> playerName;
                cout << "\nPlayer colour: ";
                cin >> playerColour;
           
            Player newPlayer = Player(i, playerName, playerColour);
           this -> players.push_back(newPlayer);
        }
}

void StartupPhase::shuffleCountries(){
    
}
