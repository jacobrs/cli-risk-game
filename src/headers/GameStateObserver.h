#ifndef STATEOBSERVER_H
#define STATEOBSERVER_H

#include "GameMap.h"
#include "Observer.h"
#include "Player.h"
#include <string>
#include <vector>

using namespace std;

class GameMap;
class Observer;

class GameStateObserver: public Observer {

  public:
    void update();
    void updateState(GameMap* map, vector<Player*> players);
    void updateAttack(int a, string attackName, string defendName, int aa, int da, bool conquered);
    void updateReinforce(int r, int p, string where);
    void updateFortify(int f, string a, string b, int m);

};

#endif
