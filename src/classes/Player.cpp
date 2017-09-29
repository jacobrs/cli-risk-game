#include "../headers/Player.h"

Player::Player(int turnIndex, string playerName, string playerColor, int numberOfDice){
  index = turnIndex;    // to be used when deciding who's turn it is
  name = playerName;
  color = playerColor;
  hand  = new Hand();
  diceRollingFacility = new DiceRolling(numberOfDice);
}
Player::Player(){
  Player::Player(0, "", "", 0);
}
void reinforce(){}
void attack(){}
void fortify(){}

Player::~Player(){
  delete hand;
  delete diceRollingFacility;
}