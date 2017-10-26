#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H

#import <string>
#import "GameStart.h"
#import "MapLoader.h"

class StartupPhase{
public:
    StartupPhase();
    ~StartupPhase();
    StartupPhase(string map, int nbPlayers);

    void printMapWithOwner();
    void shufflePlayers();
private:
    int armiesStart;
};

#endif