#include "../headers/Player.h"

Player::Player(int turnIndex, string playerName, string playerColor, int numberOfDice){
  index = turnIndex;    // to be used when deciding who's turn it is
  name = playerName;
  color = playerColor;
  hand  = new Hand();
  diceRollingFacility = new DiceRolling(numberOfDice);
}
Player::Player(){
  Player(0, "", "", 0);
}
void Player::reinforce(){}
void Player::attack(){}

/*  Moves nbToMove armies from a to b
*   1- Check if a and b are neighbours
*   2- Check if country a and b belong the to this player
*   3- Ask/Check if the amount of armies to be moved is valid (i.e.  armiesToMove < a's armies && armiesToMove >= 1)
*/
bool Player::fortify(Country* a, Country* b, int armiesToMove){
  if(a->isNeighbour(b)){
    if(a->owner->name == b->owner->name){
      if(armiesToMove < a->armies && armiesToMove >= 1){
        a->armies -= armiesToMove;
        b->armies += armiesToMove;
        return true;
      }
    }
  }
  return false;
}

Player::~Player(){
  delete hand;
  delete diceRollingFacility;
}
