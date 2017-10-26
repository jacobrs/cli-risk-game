#include "../headers/StartupPhase.h"
#include <string>
using namespace std;

StartupPhase::StartupPhase(){
}

StartupPhase::StartupPhase(string mapPlaying, int numPlayers){
    map = mapPlaying;
    nbPlayers = numPlayers;

    shufflePlayers();
    
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