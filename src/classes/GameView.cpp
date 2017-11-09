#include "../headers/GameView.h"
#include <iostream>

using namespace std;

GameView::GameView(){

}


GameView::~GameView(){
	//Detach from player when it destroys itself
	_subject->Detach(this);
}

GameView::GameView(Player* p){
    _subject = p;
    _subject->Attach(this);
}

void GameView::update(){

    display();
  
}
void GameView::display(){

}


void GameView::updateAttack(int a, string attackName, string defendName, int aa, int da, bool conquered){
	
		displayAttack(a, attackName, defendName, aa, da, conquered);
	  
}

void GameView::displayAttack(int a, string attackName, string defendName, int aa, int da, bool conquered){
	//Get the player name
	string playerName = _subject->name;

	switch(a){
		case 0:
			cout << playerName << ": Attack phase" << endl;
			break;
		case 1:
			cout << playerName << " ends their turn" << endl;
			break;
		case 2:
			cout << playerName <<  " attacks" << endl;
		case 3:
			cout << playerName << "'s country " << attackName << " attacks " << defendName << "." << endl;
			cout << attackName << " now has " << aa << " armies." <<endl;
			cout << defendName << " now has " << da << " armies." <<endl;
			break;
		case 4:
			cout << playerName << " can't attack" << endl;
			break;
		default:

			break;

	}
	
}

void GameView::updateFortify(int f){
	
		displayFortify(f);
	  
}

void GameView::displayFortify(int f){

}
void GameView::updateReinforce(int r){
	
		displayReinforce(r);
	  
}

void GameView::displayReinforce(int r){

}


