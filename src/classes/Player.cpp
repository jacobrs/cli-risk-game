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
void attack(){
  string input = "";
  cout << "Do you want to attack (y/n)" << endl;
  cin >> input;

  while(input != "y" || input != "n") //just in case user can't read
    cin >> input;

  if(input == "n") //attack phase is over
    return;

  if(input == "y"){

  }
  cout << "Something went wrong in attack phase" << endl;  // shouldn't reach here
  return;
}
void fortify(){}

Player::~Player(){
  delete hand;
  delete diceRollingFacility;
}
