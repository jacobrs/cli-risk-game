#include "../headers/Player.h"

Player::Player(int turnIndex, string playerName, string playerColor, int numberOfDice){
  index = turnIndex;    // to be used when deciding who's turn it is
  name = playerName;
  color = playerColor;
  hand  = new Hand();
  diceRollingFacility = new DiceRolling(numberOfDice);
}
Player::Player(){
  index = 0;    // to be used when deciding who's turn it is
  name = "";
  color = "";
  hand  = new Hand();
  diceRollingFacility = new DiceRolling(0);
}
void reinforce(){}
void attack(){}
void fortify(){}

Player::~Player(){
  delete hand;
  delete diceRollingFacility;
}