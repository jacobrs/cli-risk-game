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
    StartupPhase(GameMap*, vector <Player*>);    
    vector <Player*> listPlayers;
    vector <Country> countries;


    void printMapWithOwner();
    void shufflePlayers();
    void createPlayer(int);
    void shuffleCountries();

    
private:
    int armiesStart;
    string map;
    int nbPlayers;

};

#endif