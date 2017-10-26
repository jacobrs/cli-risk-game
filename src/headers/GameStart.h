#ifndef GAMESTART_H
#define GAMESTART_H

#include "GameMap.h"
#include "Player.h"
#include <string>

using namespace std;

class GameStart {

public:

    GameStart();
    GameStart(string map, int nbplayers);
    ~GameStart();

    //function to LoadMap

    //function to create Players
    Player createPlayers(int nbplayers);

    //Accessor
    int getNumOfPlayers();
    int numCountries;
    bool enterPlayer;
    string playerName;
    string playerColour;

private:
    int numOfPlayers;
    string seletedMap;
    vector <Player> players;
};


#endif