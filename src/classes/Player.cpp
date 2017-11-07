#include "../headers/Player.h"
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

Player::Player(int turnIndex, string playerName, string playerColor){
  index = turnIndex;    // to be used when deciding who's turn it is
  name = playerName;
  color = playerColor;
  hand  = new Hand();
}
Player::Player(){
  Player(0, "", "");
}
void reinforce(){}
void Player::attack(GameMap* map){ //Have to pass GameMap because can't know my countries otherwise
  string input = "";
  while(input != "n"){
    if(!ownsAttackCountry(map)){
      //Notify cannnot attack
      NotifyAttack(0);
      //cout << name << " can't attack because you don't own a country that can attack" << endl;
      return;
    }

    cout << "Does " << name << "  want to attack (y/n)" << endl;
    cin >> input;
    while(input != "y" && input != "n"){ //just in case user can't read
      input = "";
      cout << "INVALID INPUT, Do you want to attack (y/n)" << endl;
      cin >> input;
    }

    if(input == "n") //attack phase is over
      return;
      //Notify end of attack phase


    if(input == "y"){
      //choosing attackCountry
      input = "";
      cout << "Choose one of your country to attack from" << endl;
      listMyAttackCountries(map);
      cin >> input;
      Country* attackCountry = map->getCountryByName(input);
      while(attackCountry == NULL){ //just in case user can't read
        cout << "INVALID INPUT, Choose one of your country to attack from" << endl;
        listMyAttackCountries(map);
        input = "";
        cin >> input;
        attackCountry = map->getCountryByName(input);
      }

      //choosing defendCountry
      input = "";
      cout << "Choose an ennemy country to attack" << endl;
      attackCountry->listEnnemies();
      cin >> input;
      Country* defendCountry = map->getCountryByName(input);
      while(defendCountry == NULL){ //just in case user can't read
        cout << "INVALID INPUT, Choose an ennemy country to attack" << endl;
        attackCountry->listEnnemies();
        input = "";
        cin >> input;
        defendCountry = map->getCountryByName(input);
      }

      // get amount of dice to attack with
      int attackDices;
      cout << name << " is attacking " << defendCountry->owner->name << "\'s country" << endl;
      cout << name << " has an army size of " << attackCountry->armies << " you are allowed to have 1 to " << ((attackCountry->armies-1 >= 3) ? 3 : attackCountry->armies-1) << " dice." << endl;
      cout << "How many dice would you like to have?" << endl;
      cin >> attackDices;
      while(cin.fail() || attackDices > attackCountry->armies-1 || attackDices < 1 || attackDices > 3){//just in case user can't read
        cout << "INVALID INPUT, ";
        cout << name << " has an army size of " << attackCountry->armies << " you are allowed to have 1 to " << ((attackCountry->armies-1 >= 3) ? 3 : attackCountry->armies-1) << " dice." << endl;
        cout << "How many dice would you like to have?" << endl;
        cin >> attackDices;
      }

      // get amount of dice to defend with
      int defendDices;
      cout << name << " is attacking " << defendCountry->owner->name << "\'s country" << endl;
      cout << defendCountry->owner->name << " has an army size of " << defendCountry->armies << " you are allowed to have " << ((defendCountry->armies >= 2) ? 2 : 1) << " dice." << endl;
      cout << "How many dice would you like to have?" << endl;
      cin >> defendDices;
      while(cin.fail() || defendDices > defendCountry->armies || defendDices < 1 || defendDices > 2){//just in case user can't read
        cout << "INVALID INPUT, ";
        cout << defendCountry->owner->name << " has an army size of " << defendCountry->armies << " you are allowed to have " << ((defendCountry->armies >= 2) ? 2 : 1) << " dice." << endl;
        cout << "How many dice would you like to have?" << endl;
        cin >> defendDices;
      }

      //deduct armies according to the dices rolled
      DiceRolling roll;
      int* casualties = roll.attackAndDefendRoll(attackDices, defendDices);
      attackCountry->armies-=casualties[0];
      defendCountry->armies-=casualties[1];

      //if the armies in defend country reaches 0, that country is conquired by the attacker
      if(defendCountry->armies<=0){
        cout << defendCountry->name << " has been conquired, how many armies would " << attackCountry->owner->name << " like to move from " << attackCountry->name << " to " << defendCountry->name << "?" << endl;
        cout << "You can move 1 to " << attackCountry->armies-1 << " armies." << endl;
        int armiesToMove;
        cin >> armiesToMove;
        while(cin.fail() || armiesToMove > attackCountry->armies-1 || armiesToMove < 1){//just in case user can't read
          cout << "INVALID INPUT, You can move 1 to " << attackCountry->armies-1 << " armies." << endl;
          cin >> armiesToMove;
        }
        attackCountry->armies-=armiesToMove;
        defendCountry->armies=armiesToMove;
        defendCountry->owner=attackCountry->owner;
      }

      //Notify Observer on what is happening (replace with a notify method)
      cout << attackCountry->owner->name << "\'s country " << attackCountry->name << " now has " << attackCountry->armies << " armies." << endl;
      cout << defendCountry->owner->name << "\'s country " << defendCountry->name << " now has " << defendCountry->armies << " armies." << endl;
      cout << attackCountry->owner->name << (ownsAttackCountry(map)?" can":" cannot") << " attack again." << endl;
    }
  }
  return;
}

void Player::reinforce(GameMap* map){

  // count number of countries
  int countries = 0;
  int continentBonus = 0;

  vector<Country*> playersCountries;

  // calculate continents and countries owned
  for(int i = 0; i < map->numberOfContinents; i++){
    bool ownsContinent = true;
    continentBonus += map->continents[i]->bonus;
    for(int j = 0; j < map->continents[i]->numberOfCountries; j++){
      if(map->continents[i]->countries[j]->owner->name == this->name){
        countries ++;
        playersCountries.push_back(map->continents[i]->countries[j]);
      }else if(ownsContinent){
        continentBonus -= map->continents[i]->bonus;
        ownsContinent = false;
      }
    }
  }

  int armies = floor(countries / 3) + continentBonus;
  if(armies < 3){
    armies = 3;
  }

  // force an exchange if needed
  if(this->hand->handSize > 5){
    printf("Player %s is exchanging\n", this->name.c_str());
    armies += this->hand->exchange();
  }

  printf("Player %s received %d armies\n", this->name.c_str(), armies);

  // place armies received on countries
  bool invalid = false;
  while(armies > 0){
    int toPlace;
    if(invalid){
      printf("ERROR: You don't have that many armies or you don't own that territory\n");
      invalid = false;
    }
    // get armies they want to place
    printf("Enter armies to place (max %d): ", armies);
    cin >> toPlace;
    if(toPlace > armies || toPlace < 1){
      invalid = true;
    }else{
      printf("You can reinforce the following countries (enter index):\n");
      // list available countries
      for (int i = 0; i < playersCountries.size(); i++){
        printf("[%d] %s (%d armies)\n", i, playersCountries[i]->name.c_str(), playersCountries[i]->armies);
      }
      int selected;
      cin >> selected;
      // place if country is in list of available countries
      if(selected >= 0 && selected < playersCountries.size()){
        playersCountries[selected]->armies += toPlace;
        armies -= toPlace;
        printf("Placing %d army/armies on %s\n", toPlace, playersCountries[selected]->name.c_str());
      }else{
        invalid = true;
      }
    }
  }

  printf("\nReinforcement phase complete\n\n\n");
  
}

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

bool Player::ownsAttackCountry(GameMap* map){ //checks if player owns a country that can attack
  for(int continent = 0; continent < map->numberOfContinents; continent++){
    Continent* con = map->continents[continent];
    for(int country = 0; country < con->numberOfCountries; country++){
      Country* coun = con->countries[country];
      if(coun->owner != NULL && coun->owner->name == name && coun->hasEnnemies() && coun->armies >= 2){ // if this player is the owner, has ennemies and armies >= 2 (can attack)
          return true;
      }
    }
  }
  return false;
}

void Player::listMyAttackCountries(GameMap* map){ //Prints out attack countries that belong to this player
  for(int continent = 0; continent < map->numberOfContinents; continent++){
    Continent* con = map->continents[continent];
    for(int country = 0; country < con->numberOfCountries; country++){
      Country* coun = con->countries[country];
      if(coun->owner != NULL && coun->owner->name == name && coun->hasEnnemies() && coun->armies >= 2){ // if this player is the owner, has ennemies and armies >= 2 (can attack)
        cout << coun->name << ", " ;
      }
    }
    cout << endl;
  }
}

Player::~Player(){
  delete hand;
}

void Player::mockReinforce(){
  printf("Mock Reinforcement Phase\n");
}

void Player::mockAttack(){
  printf("Mock Attack Phase\n");
}

void Player::mockFortify(){
  printf("Mock Fortification Phase\n");
}
