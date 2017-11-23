#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "MapLoader.h"
#include "Player.h"
#include "Deck.h"
#include <string>
#include <vector>

using namespace std;

class Tournament {

public:
  GameMap **gameMaps;
  vector<Player*> players;
  int gamesPlayed;
  int maxTurns;

  Tournament();
  ~Tournament();
  void startTournament();
};

#endif
