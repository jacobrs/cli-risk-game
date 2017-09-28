#include "../headers/Deck.h"

using namespace std;

Deck::Deck(int numOfCards){ 
    createDeck(numOfCards);
    drawnPile.empty();
}

Deck::Deck(){
    createDeck(0);
}

void Deck::createDeck(int numberOfCards){
 
    for(counter = 0; counter < numberOfCards; counter++){

        if(counter % 3 ==0){
            Card newCard = Card("infantry");
            this -> riskDeck.push_back(newCard);
        } else if(counter % 3 == 1){
            Card newCard = Card("artillery");
            this -> riskDeck.push_back(newCard);
        } else if(counter % 3 == 2){
            Card newCard = Card("cavalry");
            this -> riskDeck.push_back(newCard);
        }
    }
}

void Deck::shuffleDeck(){
    random_device rd;
	mt19937 g(rd());

	shuffle(riskDeck.begin(), riskDeck.end(), g);
}

Card Deck::draw(){

    Card cardDrawn = riskDeck.front();
    riskDeck.erase(riskDeck.begin());
    drawnPile.push_back(cardDrawn);
    return cardDrawn;

}

void Deck::printDeck() {

    int length = riskDeck.size();
    Card current;

    cout << "\nDeck" << endl;
    for (int i = 0; i<length; i++){
        current = riskDeck.at(i);
        cout << current.getCardType() << endl;
    }
}

void Deck::printDrawnPile() {
    
        int length = drawnPile.size();
        Card current;
        int infantryCounter =0;
        int artilleryCounter =0;
        int cavalryCounter =0;
    
        cout << "\nDeck drawn" << endl;
        for (int i = 0; i<length; i++){
            current = drawnPile.at(i);
            if (current.getCardType() == "artillery"){
                artilleryCounter++;
            }else if(current.getCardType() == "infantry"){
                infantryCounter++;
            }else if(current.getCardType() == "cavalry"){
                cavalryCounter++;
            }else{

            }
        }
        cout << "\nartillery: " << artilleryCounter <<"\ninfantry: "<<infantryCounter << "\ncavalry: "<< cavalryCounter <<endl;
    }

