#ifndef GAME_H
#define GAME_H

#include "GameMap.h"
#include "Player.h"
#include "Deck.h"
#include "GameSubject.h"
#include "GameStateObserver.h"
#include "DiceRolling.h"
#include <vector>

using namespace std;

class Game{
private:
  GameMap* gameMap;

public:
  Game(GameMap* map, vector<Player*>);
  ~Game();
  void startGame();
  bool isWon();
  void observeGame();
  GameSubject* stateChanges;
  GameStateObserver* stateObserver;
  vector<Player*> players;

};

#endif
