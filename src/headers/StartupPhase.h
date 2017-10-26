#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H

#include "GameMap.h"
#include "MapLoader.h"

#include <string>
#include <vector>
using namespace std;


class StartupPhase{
public:
    StartupPhase();
    ~StartupPhase();
    StartupPhase(string, int);    
    vector <Player> players;
    vector <Country> countries;


    void printMapWithOwner();
    void shufflePlayers();
    void createPlayer();
    void shuffleCountries();

    
private:
    int armiesStart;
    string map;
    int nbPlayers;

};

#endif