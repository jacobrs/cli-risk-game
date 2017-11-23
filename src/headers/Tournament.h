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
  int nbMaps;
  int nbStrats;
  int nbGames;
  int nbTurns;
  vector<string> maps;
  vector<string> strats;

  Tournament();
  Tournament(int, int, int, int, vector<string>, vector<string>);
  ~Tournament();
  void startTournament();
};

#endif
