#include "../headers/Hand.h"
#include <string>

Hand::Hand(){
    handSize = 0;
}

int Hand::exchange(){

    static int exchangeCounter = 1;
    if(inHandInf.size()>=3){
       inHandInf.erase(inHandInf.begin(), inHandInf.begin()+3);
    } else if(inHandCav.size()>=3){
        this -> inHandCav.erase(inHandCav.begin(), inHandCav.begin()+3);
    } else if(inHandArt.size()>=3){
       this -> inHandArt.erase(inHandArt.begin(), inHandArt.begin()+3);
    } else if (inHandInf.size()>=1 && inHandCav.size()>=1 && inHandArt.size()>=1){
        this -> inHandInf.pop_back();
        this -> inHandCav.pop_back();
        this -> inHandArt.pop_back();
    } else{
        cout << "not enough cards" << endl;
        return 0;
    }
    this -> handSize -= 3;
    int addedArmies = exchangeCounter*5;
    exchangeCounter++;
    return addedArmies;
}

void Hand::addCard(Card newCardHand){

    if (newCardHand.getCardType() == "infantry"){
       this -> inHandInf.push_back(newCardHand);
       this -> handSize++;
    } else if (newCardHand.getCardType() == "artillery"){
        this -> inHandArt.push_back(newCardHand);
        this -> handSize++;
    } else if (newCardHand.getCardType() == "cavalry"){
       this -> inHandCav.push_back(newCardHand);
       this -> handSize++;
    }else{
        cout << "error"<< endl;
    }
}

void Hand::printHand(){

    string CYAN = "\x1b[1;36m";
    string DEFAULT = "\x1b[0m";

    printf("%s| %sHand Infantry: %lu\n", CYAN.c_str(), DEFAULT.c_str(), inHandInf.size());
    printf("%s| %sHand Artillery: %lu\n", CYAN.c_str(), DEFAULT.c_str(), inHandArt.size());
    printf("%s| %sHand Cavalry: %lu\n\n", CYAN.c_str(), DEFAULT.c_str(), inHandCav.size());
  
}
