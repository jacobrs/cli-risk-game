#include "../headers/Card.h"

Card::Card(string cardType)
{
    this->cardType = cardType;
}

Card::Card()
{
    Card::Card("");
}

string Card::getCardType(){

    return this -> cardType;
}

void Card::setCardType(string cType){
    this -> cardType = cType;
}
