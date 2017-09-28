
#include "headers/Player.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int args, char** argv){
    srand (time(NULL));
    string name = "";
    int numberOfDice = 0;
    int player1NumberOfDice = 0;
    int numberOfAttempts = 0;

    cout<<"Welcome Player please enter your name: ";
    cin>> name;
    cout<<"\nPlease enter the number of dice you would like to use: ";
    cin>> numberOfDice;

    while(numberOfAttempts < 3 && (player1NumberOfDice > 3 || player1NumberOfDice < 1)){
      if (numberOfAttempts > 0) cout<<"\nYou made an error while entering values integers between 1 and 3 only!\n";
      cout<< name <<" choose how many dice you would like: 1, 2 or 3? ";
      cin>> player1NumberOfDice;
      numberOfAttempts++;
    }
    if(player1NumberOfDice < 4 && player1NumberOfDice > 0){
        Player player1 = new Player(1, name, "red", numberOfDice);

        count<< " Drawing a card from the deck to the hand of " << name << "\n";
        Deck gameDeck = Deck(15);
        Card drawn1 = gameDeck.draw();
        cout <<"\n Card drawn: "<< drawn1.printCard() <<endl;
        player1->hand.addCard(drawn1);
        player1->hand.printHand();
    }
    player1->~Player();
}