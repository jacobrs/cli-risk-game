#include "../headers/Player.h"

Player::Player(int turnIndex, string playerName, string playerColor){
  index = turnIndex;    // to be used when deciding who's turn it is
  name = playerName;
  color = playerColor;
}