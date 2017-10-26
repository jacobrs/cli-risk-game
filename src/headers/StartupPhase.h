#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H

#include <string>
#include "GameStart.h"
#include "MapLoader.h"

class StartupPhase{
public:
    StartupPhase();
    ~StartupPhase();
    StartupPhase(string, int);

    void printMapWithOwner();
    void shufflePlayers();
    void createPlayer();

    
private:
    int armiesStart;
    string map;
    int nbPlayers;
    vector <Player> players;
};

#endif