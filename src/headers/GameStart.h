#ifndef GAMESTART_H
#define GAMESTART_H

#include "MapLoader.h"
#include "Player.h"
#include "Deck.h"
#include <string>
#include <vector>

using namespace std;

class GameStart {

public:

    GameStart();
    GameStart(string, int);
    vector<Player> players;
    Deck playDeck;
    //~GameStart();

    //function to LoadMap

    //function to create Players
    void createPlayers(int);

    //Accessor
    int getNumOfPlayers();
    int numCountries;
    bool enterPlayer;
    string playerName;
    string playerColour;
    int deckSize;

private:
    int numOfPlayers;
    string map;
    
};


#endif