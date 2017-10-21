#include "headers/Country.h"
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

    while(numberOfAttempts < 3 && (player1NumberOfDice > 3 || player1NumberOfDice < 1)){
      if (numberOfAttempts > 0) cout<<"\nYou made an error while entering values integers between 1 and 3 only!\n";
      cout<< name <<" choose how many dice you would like: 1, 2 or 3? ";
      cin>> player1NumberOfDice;
      numberOfAttempts++;
    }
    Player *player1 = new Player(1, name, "red", player1NumberOfDice);

    printf("Player with name %s was created with diceRollingFacility containing %d dice.\n", player1->name.c_str(), player1->diceRollingFacility->number);

    if(player1NumberOfDice < 4 && player1NumberOfDice > 0){

        cout << "Drawing 2 cards from the deck to the hand of " << name << "\n";
        Deck gameDeck = Deck(15);
        Card drawn1 = gameDeck.draw();
        cout <<"\nCard drawn: "<< drawn1.printCard() <<endl;
        player1->hand->addCard(drawn1);
        
        Card drawn2 = gameDeck.draw();
        cout <<"\nCard drawn: "<< drawn2.printCard() <<endl;
        player1->hand->addCard(drawn2);
        player1->hand->printHand();
    }

    Country* canada = new Country("Canada");
    canada->owner = player1;

    printf("%s is owned by %s\n", canada->name.c_str(), canada->owner->name.c_str());
    
    delete player1;
}
