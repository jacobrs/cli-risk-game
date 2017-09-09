#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player{
public:
  int index;
  string name;
  string color;

  Player(int, string, string);
  Player();
};

#endif