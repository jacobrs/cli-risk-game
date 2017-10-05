#include "../headers/Player.h"
#include <algorithm>

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
void Player::reinforce(){}
void Player::attack(Country *attackingCountry, Country *enemyCountry){
  string is_attacking = "";
  int numDiceAvailable = 0; 

  cout<< name <<" would you like to attack " << enemyCountry->owner->name << "?\n";
  cout<< "Type no to skip the attack phase and any other character to attack: ";
  cin>> is_attacking;
  if(is_attacking != "no"){
    int maxDice = attackingCountry->armies > 3 ? 3 : attackingCountry->armies;
    cout<< name << " you can have between 1 and" << maxDice << " dice. Please choose a number in that range: "; 
    cin>> numDiceAvailable;
    if(numDiceAvailable <= maxDice && numDiceAvailable > 0){
      delete diceRollingFacility;
      diceRollingFacility = new DiceRolling(numDiceAvailable);
      numDiceAvailable = 0;
      maxDice = enemyCountry->armies > 3 ? 3: enemyCountry->armies;
      cout<< enemyCountry->owner->name << " you can have between 1 and" << maxDice << " dice. Please choose a number in that range: "; 
      cin>> numDiceAvailable;
      if(numDiceAvailable <= maxDice && numDiceAvailable > 0){
        delete enemyCountry->owner->diceRollingFacility;
        enemyCountry->owner->diceRollingFacility = new DiceRolling(numDiceAvailable);
        diceBattle(enemyCountry->owner->diceRollingFacility);
      }
      else cout<< "\n"<< enemyCountry->owner->name <<" you did not choose a valid number in the range provided try again";
    }
    else cout<< "\n"<< name <<" you did not choose a valid number in the range provided try again";

  }
}
void Player::fortify(){}
bool sortByDieSide(Die *lhs, Die *rhs){ return lhs->dieSide < rhs->dieSide; }
void Player::diceBattle(DiceRolling *enemyDice){
  //roll dice for both
  this->diceRollingFacility->rollDice();
  enemyDice->rollDice();
  //sort each dice array by descending order into a new array
  /*int *playerSortedDice = new int [this->diceRollingFacility->number];
  int *enemySortedDice = new int [enemyDice->number];
  for(int i = 0; i < this->diceRollingFacility->number; i++){
    if(this->diceRollingFacility->dice[i].dieSide >= this->diceRollingFacility->dice[i+1].dieSide){
      playerSortedDice[i] = this->diceRollingFacility->dice[i].dieSide;
    }
    else {
      playerSortedDice[i] = this->diceRollingFacility->dice[i+1].dieSide;
    }
  }*/
  //compare the same indexes to eachother to determine winner
  sort(this->diceRollingFacility->dice, this->diceRollingFacility->dice + this->diceRollingFacility->number, sortByDieSide);
  for(int i = 0; i <  this->diceRollingFacility->number; i++)
    cout<< this->diceRollingFacility->dice[i]->dieSide << "\n";
  for(int i = 0; i < this->diceRollingFacility->number; i++){
    this->diceRollingFacility->dice[i]->dieSide > enemyDice->dice[i]->dieSide;
  }
  //foreach dice pair starting from highest result
}

Player::~Player(){
  delete hand;
  delete diceRollingFacility;
}