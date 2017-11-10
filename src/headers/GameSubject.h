#ifndef G_SUBJECT_H
#define G_SUBJECT_H

#include "GameStateObserver.h"
#include "GameMap.h"
#include "Player.h"
#include <string>
#include <list>
#include <vector>
using namespace std;

class GameSubject{

public:
    void Attach(GameStateObserver* O);
    void Detach(GameStateObserver* O);
    void Notify(GameMap* map, vector<Player*> players);

    GameSubject();
    ~GameSubject();
private:
    list <GameStateObserver*> *_observers;

};

#endif
