#ifndef GAMESTART_H
#define GAMESTART_H

#include "MapLoader.h"
#include "Player.h"
#include <string>

using namespace std;

class GameStart {

public:

    GameStart();
    GameStart(string, int);
    //~GameStart();

    //function to LoadMap

    //function to create Players
    void createPlayers(int nbplayers);

    //Accessor
    int getNumOfPlayers();
    int numCountries;
    bool enterPlayer;
    string playerName;
    string playerColour;

private:
    int numOfPlayers;
    string map;
    vector <Player> players;
};


#endif