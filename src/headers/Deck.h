#ifndef DECK_H
#define DECK_H 

#include "Card.h"
#include "Hand.h"
#include "Country.h"
#include <string>
#include <vector>

using namespace std;

class Deck:{

public:

    int numberOfCards;
    int infantryCounter;
    int cavalryCounter;
    int artilleryCounter;
    int remainder; 

    //Constructor
    Deck();
    
    //Method to generate deck
    void createDeck(int);

    //Methods to draw and transfer card to hand
    Card draw();
    
    //Method to look through the deck

    //Method to shuffle
    void shuffleDeck();



private:
    vector<Card> riskDeck;

};


#endif