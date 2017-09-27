#include "headers/Die.h"
#include "headers/DiceRolling.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int args, char** argv){

  srand (time(NULL));
  
  bool rollDice = true;
  string user_exit = "";
  string player1Input = "";
  string player2Input = "";
  int player1NumberOfDice = 0;
  int player2NumberOfDice = 0;
  int numberOfAttempts = 0;

  cout<< "Welcome to the Dice rolling facility!\n";
  while(numberOfAttempts < 3 && (player1NumberOfDice > 3 || player1NumberOfDice < 1 || player2NumberOfDice > 3 || player2NumberOfDice < 1)){
    if (numberOfAttempts > 0) cout<<"\nYou made an error while entering values integers between 1 and 3 only!\n";
    cout<< "Player 1 choose how many dice you would like: 1, 2 or 3? ";
    cin>> player1NumberOfDice;
    cout<<"\nPlayer 2 choose your number of dice: ";
    cin>>player2NumberOfDice;

    numberOfAttempts++;
  }
  if(player1NumberOfDice < 4 && player1NumberOfDice > 0 && player2NumberOfDice < 4 && player2NumberOfDice > 0){
    
  DiceRolling* diceSet1 = new DiceRolling(player1NumberOfDice);
  DiceRolling* diceSet2 = new DiceRolling(player2NumberOfDice);

  while(rollDice){
    cout<< "Dice are rolling...\n";

    diceSet1->rollDice();
    diceSet2->rollDice();
  
    for(int i = 0; i < player1NumberOfDice; i++){
      printf("\ndice set 1: die %d rolls %d", i + 1, diceSet1->dice[i]->dieSide, "\n");
    }
    int numberOfRollsDiceSet1 = diceSet1->numberOfRolls;
    for(int i = 0; i < 6; i++){
      printf("\ndice set 1: percentage of value %d rolls %.2f", i+1, (diceSet1->valuesRolled[i]/(double)numberOfRollsDiceSet1)*100, "\n");
    }
    printf("\ndice set 1: total %d", diceSet1->total, "\n");
  
    for(int i = 0; i < player2NumberOfDice; i++){
      printf("\ndice set 2: die %d rolls %d", i + 1, diceSet2->dice[i]->dieSide, "\n");
    }
    int numberOfRollsDiceSet2 = diceSet2->numberOfRolls;
    for(int i = 0; i < 6; i++){
      printf("\ndice set 2: percentage of value %d rolls %.2f", i+1, (diceSet2->valuesRolled[i]/(double)numberOfRollsDiceSet2)*100, "\n");
    }
    printf("\ndice set 2: total %d", diceSet2->total, "\n");

    diceSet1->total = 0;
    diceSet2->total = 0;

    cout<< "\nPress any character followed by enter to roll again, \n
            type exit and press enter to terminate the program: ";
    cin>> user_exit;
    user_exit == "exit"? rollDice = false: rollDice = true;    
  }
  
  }
  else cout<<"\nYou have failed to enter a proper value for the number of dice. Terminating....";
}
