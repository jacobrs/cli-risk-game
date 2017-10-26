#ifndef GAME_H
#define GAME_H

#include "GameMap.h"
#include "Player.h"
#include "Deck.h"
#include "DiceRolling.h"
#include <vector>

using namespace std;

class Game{
private:
  vector<Player> players;
  GameMap* gameMap;

public:
  Game(GameMap* map, int numberOfPlayers);
  ~Game();
  void startGame();

};

#endif
