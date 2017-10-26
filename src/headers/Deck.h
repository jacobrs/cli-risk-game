#ifndef DECK_H
#define DECK_H

#include "Card.h"

#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Deck{

public:
   
    int infantryCounter;
    int artilleryCounter;
    int cavalryCounter;
    int counter;
    

    //Constructor
    Deck();
    Deck(int);
    
    //Method to generate deck
    void createDeck(int);

    //Methods to draw and transfer card to hand and copies the drawn card to the drawn deck
    Card draw();

    //Method to count type of drawn cards
    Deck addDrawnPile(Card);

    //Method to shuffle
    void shuffleDeck();

    //Method to print out deck
    void printDeck();
    void printDrawnPile();

    //Accessor for size
    int getSize();

private:
    vector<Card> riskDeck;
    vector<Card> drawnPile;
    int currentCard;
    int size;

};

#endif 
