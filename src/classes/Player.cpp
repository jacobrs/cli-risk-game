#include "../headers/Player.h"
#include "../headers/AggressivePlayer.h"
#include "../headers/BenevolentPlayer.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>

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
void Player::executeStrategy(GameMap *map){
  this->strategy->execute(this, map);
}
void Player::attack(GameMap* map){ //Have to pass GameMap because can't know my countries otherwise

NotifyAttack(0, "", "" , 0, 0, false);

string playerType = "";

if(dynamic_cast<AggressivePlayer*>(this->strategy) != nullptr){
  cout<< name <<" is an Aggressive computer player"<<endl;  
  playerType = "A";
}
else if(dynamic_cast<BenevolentPlayer*>(this->strategy) != nullptr){
  cout<< name <<" is an Benevolent computer player"<<endl;  
  playerType = "B";
}

string input = "";
  while(input != "n"){
    bool conquered = false;
    if(!ownsAttackCountry(map)){
      //Notify cannnot attack
      NotifyAttack(4, "", "", 0, 0 , conquered);
      //cout << name << " can't attack because you don't own a country that can attack" << endl;
      return;
    }

    cout << "Does " << name << "  want to attack (y/n)" << endl;

    if(playerType == "A") {input = "y"; cout<<"y"<<endl;}
    else if(playerType == "B") {input = "n"; cout<<"n"<<endl;}
    else cin >> input;
    while(input != "y" && input != "n"){ //just in case user can't read
      input = "";
      cout << "INVALID INPUT, Do you want to attack (y/n)" << endl;
      cin >> input;
    }

    cin.ignore();
    if(input == "n") {//attack phase is over
      //Notify end of attack phase
      NotifyAttack(1, "", "", 0 , 0, conquered);
      return;}

    if(input == "y"){
      NotifyAttack(2, "", "" , 0, 0, conquered);
      //choosing attackCountry
      input = "";
      cout << "Choose one of your country to attack from" << endl;
      listMyAttackCountries(map);
      if(playerType == "A") {
        input = getStrongetAttackCountry(map);
        cout<< name <<" chooses it's strongest country: " << input << endl;
      }
      else 
        getline(cin, input);
      Country* attackCountry = map->getCountryByName(input);
      while(attackCountry == NULL){ //just in case user can't read
        cout << "INVALID INPUT, Choose one of your country to attack from" << endl;
        listMyAttackCountries(map);
        input = "";
        getline(cin, input);
        attackCountry = map->getCountryByName(input);
      }

      //choosing defendCountry
      input = "";
      cout << "Choose an ennemy country to attack" << endl;
      attackCountry->listEnnemies();
      if(playerType == "A") {
        input = attackCountry->getWeakestEnemy();
        cout<< name <<" chooses it's oponent's weakest country: " << input << endl;
      }
      else 
        getline(cin, input);
      Country* defendCountry = map->getCountryByName(input);
      while(defendCountry == NULL){ //just in case user can't read
        cout << "INVALID INPUT, Choose an ennemy country to attack" << endl;
        attackCountry->listEnnemies();
        input = "";
        getline(cin, input);
        defendCountry = map->getCountryByName(input);
      
      }

      // get amount of dice to attack with
      int attackDices;
      cout << name << " is attacking " << defendCountry->owner->name << "\'s country" << endl;
      cout << name << " has an army size of " << attackCountry->armies << " you are allowed to have 1 to " << ((attackCountry->armies-1 >= 3) ? 3 : attackCountry->armies-1) << " dice." << endl;
      cout << "How many dice would you like to have?" << endl;
      if(playerType == "A") attackDices = ((attackCountry->armies-1 >= 3) ? 3 : attackCountry->armies-1);
      else cin >> attackDices;
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
      
      if(dynamic_cast<AggressivePlayer*>(defendCountry->owner->strategy) != nullptr ||
      dynamic_cast<BenevolentPlayer*>(defendCountry->owner->strategy) != nullptr) {
        defendDices = ((defendCountry->armies >= 2) ? 2 : 1);
        cout<<defendDices<<endl;
      }
      else cin >> defendDices;
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
        conquered = true;
        cout << defendCountry->name << " has been conquired, how many armies would " << attackCountry->owner->name << " like to move from " << attackCountry->name << " to " << defendCountry->name << "?" << endl;
        cout << "You can move 1 to " << attackCountry->armies-1 << " armies." << endl;
        int armiesToMove;
        if(playerType == "A") armiesToMove = attackCountry->armies-1;
        else cin >> armiesToMove;
        while(cin.fail() || armiesToMove > attackCountry->armies-1 || armiesToMove < 1){//just in case user can't read
          cout << "INVALID INPUT, You can move 1 to " << attackCountry->armies-1 << " armies." << endl;
          cin >> armiesToMove;
        }
        attackCountry->armies-=armiesToMove;
        defendCountry->armies=armiesToMove;
        defendCountry->owner=attackCountry->owner;
      }
   
      //Notify Observer on what is happening 
      string attackName = attackCountry->name;
      string defendName = defendCountry->name;
      int attackArmies = attackCountry->armies;
      int defendArmies = defendCountry->armies;

      NotifyAttack(3, attackName, defendName, attackArmies , defendArmies, conquered);
      
    }
  }
  return;
}

void Player::reinforce(GameMap* map){
  NotifyReinforce(3, 0, "");
  //set player type depending on the strategy that is set for it
  string playerType = "";
  
  if(dynamic_cast<AggressivePlayer*>(this->strategy) != nullptr){
    cout<< name <<" is an Aggressive computer player"<<endl;  
    playerType = "A";
  }
  else if(dynamic_cast<BenevolentPlayer*>(this->strategy) != nullptr){
    cout<< name <<" is an Benevolent computer player"<<endl;  
    playerType = "B";
  }
  
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
    NotifyReinforce(2, 0, "");
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
    if(playerType == "A"|| playerType == "B"){toPlace = armies; cout<<armies<<endl;}
    else cin >> toPlace;
    if(toPlace > armies || toPlace < 1){
      invalid = true;
    }else{
      printf("You can reinforce the following countries (enter index):\n");
      // list available countries
      int armiesOfWeakestContry = 1000;
      int armiesOfStrongestCountry = 0;
      int indexOfWeakestCountry = 0;
      int indexOfStrongestCountry = 0;
      for (int i = 0; i < playersCountries.size(); i++){
        printf("[%d] %s (%d armies)\n", i, playersCountries[i]->name.c_str(), playersCountries[i]->armies);
        //determine strongest country
        if(playersCountries[i]->armies > armiesOfStrongestCountry){
          armiesOfStrongestCountry = playersCountries[i]->armies;
          indexOfStrongestCountry = i;
        }
        //determine weakest country
        if(playersCountries[i]->armies < armiesOfWeakestContry){
          armiesOfWeakestContry = playersCountries[i]->armies;
          indexOfWeakestCountry = i;
        }
      }
      int selected;
      if(playerType == "A"){
        cout<<"Aggressive player will reinforce its strongest country " <<indexOfStrongestCountry<<endl;
        selected = indexOfStrongestCountry;
      }
      else if(playerType == "B"){
        cout<<"Benevolent player will reinforce its weakest country " <<indexOfWeakestCountry<<endl;
        selected = indexOfWeakestCountry;
      }
      else cin >> selected;
      // place if country is in list of available countries
      if(selected >= 0 && selected < playersCountries.size()){
        playersCountries[selected]->armies += toPlace;
        armies -= toPlace;
       string  countryReinforced = playersCountries[selected]->name.c_str();
       // printf("Placing %d army/armies on %s\n", toPlace, playersCountries[selected]->name.c_str());
      NotifyReinforce(1,toPlace,countryReinforced);
      }else{
        invalid = true;
      }
    }
  }
  // Replace current print with a notification phase end to observer
 // printf("\nReinforcement phase complete\n\n\n");
  NotifyReinforce(0,0,"");
  
}

/*  Moves nbToMove armies from a to b
*   1- Check if a and b are neighbours
*   2- Check if country a and b belong the to this player
*   3- Ask/Check if the amount of armies to be moved is valid (i.e.  armiesToMove < a's armies && armiesToMove >= 1)
*/
bool Player::fortify(Country* a, Country* b, int armiesToMove){
  NotifyFortify(3, "", "", 0);
  if(a->isNeighbour(b)){
    if(a->owner->name == b->owner->name){
      if(armiesToMove < a->armies && armiesToMove >= 1){
        a->armies -= armiesToMove;
        b->armies += armiesToMove;
        string nameA = a->name;
        string nameB = b->name;
        NotifyFortify(1, nameA, nameB, armiesToMove);
        return true;
      }
    }
  }
  
  NotifyFortify(2, "", "", 0);
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

string Player::getStrongetAttackCountry(GameMap* map){
  int armiesInStrongestCountry = 0;
  string stronggestCountry = "";
  for(int continent = 0; continent < map->numberOfContinents; continent++){
    Continent* con = map->continents[continent];
    for(int country = 0; country < con->numberOfCountries; country++){
      Country* coun = con->countries[country];
      if(coun->owner != NULL && 
          coun->owner->name == name && 
          coun->hasEnnemies() && coun->armies >= 2 && 
          coun->armies > armiesInStrongestCountry){ // if this player is the owner, has ennemies and armies >= 2 (can attack) and this country has more armies than the last strongest country choose this one
            //cout << coun->name << ", " << " with " <<  coun->armies << endl;
            armiesInStrongestCountry = coun->armies;
            stronggestCountry = coun->name;
      }
    }
  }
  return stronggestCountry;
}
string Player::getStrongetCountry(GameMap* map){
  int armiesInStrongestCountry = 0;
  string stronggestCountry = "";
  for(int continent = 0; continent < map->numberOfContinents; continent++){
    Continent* con = map->continents[continent];
    for(int country = 0; country < con->numberOfCountries; country++){
      Country* coun = con->countries[country];
      if(coun->owner != NULL && 
          coun->owner->name == name){ // if this player is the owner, has ennemies and armies >= 2 (can attack) and this country has more armies than the last strongest country choose this one
            cout << coun->name << ", " << " with " <<  coun->armies << " armies"<< endl;
            if(coun->armies > armiesInStrongestCountry){
              armiesInStrongestCountry = coun->armies;
              stronggestCountry = coun->name;
            }
      }
    }
  }
  return stronggestCountry;
}
string Player::getWeaketCountry(GameMap* map){
  int armiesInWeakestCountry = 1000;
  string weakestCountry = "";
  for(int continent = 0; continent < map->numberOfContinents; continent++){
    Continent* con = map->continents[continent];
    for(int country = 0; country < con->numberOfCountries; country++){
      Country* coun = con->countries[country];
      if(coun->owner != NULL && 
          coun->owner->name == name){ // if this player is the owner, has ennemies and armies >= 2 (can attack) and this country has less armies than the last weakest country choose this one
            cout << coun->name << ", " << " with " <<  coun->armies << " armies"<< endl;
            if(coun->armies > armiesInWeakestCountry){
              armiesInWeakestCountry = coun->armies;
              weakestCountry = coun->name;
            }
      }
    }
  }
  return weakestCountry;
}
Player::~Player(){
  delete hand;
  delete strategy;
}

