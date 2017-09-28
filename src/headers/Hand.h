#ifndef HAND_H
#define HAND_H

#include "Deck.h"

class Hand{

public:
 
    Hand();
    Hand(int);
    static int exchangeCounter;
    int addedArmies;
    int handSize;

    int getExchangeCounter();
    void setExchangeCounter();

    int exchange();
    void addCard(Card);
    void printHand();

private:
    vector<Card> inHandArt;
    vector<Card> inHandInf;
    vector<Card> inHandCav;
    
};

#endif