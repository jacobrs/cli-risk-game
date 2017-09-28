#include "headers/Hand.h"

int main (int agrs, char** argv){

//Deck 
Deck gameDeck = Deck(15);

  gameDeck.printDeck();
  gameDeck.printDrawnPile();
  gameDeck.shuffleDeck();
  gameDeck.printDeck();

  Card drawn1 = gameDeck.draw();
  cout <<"\n Card drawn: "<< drawn1.printCard() <<endl;  

  gameDeck.printDeck();     

  Hand hand1 = Hand();
  hand1.addCard(drawn1);

  hand1.printHand();

  Card drawn2 = gameDeck.draw();
  Card drawn3 = gameDeck.draw();
  Card drawn4 = gameDeck.draw();
  Card drawn5 = gameDeck.draw();

  hand1.addCard(drawn2);
  hand1.addCard(drawn3);
  hand1.addCard(drawn4);
  hand1.addCard(drawn5);
  hand1.printHand();
  gameDeck.printDrawnPile();

  gameDeck.printDeck();
  
  int newArmy =0;

  if (hand1.handSize >= 5){
    newArmy = hand1.exchange();
  }
  cout << "Bonus armies from exchanging: " << newArmy <<endl;

  hand1.printHand();

  Hand hand3 = Hand();

  cout << hand1.handSize << endl;
  cout << hand3.handSize << endl;

  Card drawn6 = gameDeck.draw();
  Card drawn7 = gameDeck.draw();
  Card drawn8 = gameDeck.draw();
  Card drawn9 = gameDeck.draw();
  Card drawn10 = gameDeck.draw();

  hand3.addCard(drawn6);
  hand3.addCard(drawn7);
  hand3.addCard(drawn8);
  hand3.addCard(drawn9);

  hand3.printHand();
  newArmy = hand3.exchange();

  cout << "Bonus armies from exchanging: " << newArmy << endl;
  

return 0;
}