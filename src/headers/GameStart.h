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
    vector<Player*> players;
    Deck playDeck;
    int numCountries;
    bool enterPlayer;
    string playerName;
    string playerColour;
    int deckSize;
    GameMap *gameMap;

    GameStart();
    GameStart(string, int);
    ~GameStart();
    //function to create Players
    void createPlayers(int);
    //Accessor
    int getNumOfPlayers();

private:
    int numOfPlayers;
    string map;
    
};


#endif