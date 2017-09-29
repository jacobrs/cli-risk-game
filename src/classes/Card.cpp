#include "../headers/Card.h"

Card::Card(string cardType)
{
    this->cardType = cardType;
}

Card::Card()
{
    this -> cardType ="";
}

string Card::getCardType(){

    return this -> cardType;
}

void Card::setCardType(string cType){
    this -> cardType = cType;
}

string Card::printCard(){
    return this -> cardType;
}
