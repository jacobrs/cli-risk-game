#include "../headers/Deck.h"
#include <algorithm>
#include <random>

using namespace std;

Deck::Deck()(
    numberOfCards = numberOfCountries;
    createDeck(numberOfCards);
    shuffle();
)

void Deck::createDeck(deckSize){
 
    for(i=0; i<(deckSize);i++){

        remainder = deckSize%3;

        if (remainder==0)
            {
                deck<i> = card("infantry");
            }
        else if (remainder==1)
            {
                deck<i> = card("artillery");
            }
        else if (remainder==2)
            {
                deck<i> = card("cavalry");
            }
        else{}
        
}
}

void Deck::shuffleDeck(){

    for(int j = 0; j<numberOfCards; j++){
        int r = j + rand() % (numberOfCards - j);
        swap(elements[j],elements[r]);
    }

}

Card Deck::draw(){

}
