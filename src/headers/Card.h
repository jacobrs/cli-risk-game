#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card{
public:

    //Constructor
    Card(string cardType);
    string print() const;
    Card();

    //Accessor & Mutators
    string getCardType();
    void setCardType(string type);

    string printCard();

private:
    string cardType;
};

#endif