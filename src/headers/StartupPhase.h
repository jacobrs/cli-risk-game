#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H

#include <string>
#include "GameStart.h"
#include "MapLoader.h"

class StartupPhase{
public:
    StartupPhase();
    ~StartupPhase();
    StartupPhase(string map, int nbPlayers);

    void printMapWithOwner();
    void shufflePlayers();
private:
    int armiesStart;
    string map;
    int nbPlayers;
    vector <Player> players;
};

#endif