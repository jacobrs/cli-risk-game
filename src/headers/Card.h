#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card{
public:

    //Constructor
    Card(string cardType);
    Card();

    //Accessor & Mutators
    string getCardType();
    void setCardType(string type);

private:
    string cardType;
};

#endif