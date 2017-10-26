
#ifndef STARTUPPHASE2_H
#define STARTUPPHASE2_H

#include <string>
#include "GameStart.h"
#include "MapLoader.h"

class StartupPhase{
public:
    StartupPhase();
    ~StartupPhase();
    StartupPhase(string, int);    
    vector <Player> players;

    void printMapWithOwner();
    void shufflePlayers();
    void createPlayer();

    
private:
    int armiesStart;
    string map;
    int nbPlayers;

};

#endif
