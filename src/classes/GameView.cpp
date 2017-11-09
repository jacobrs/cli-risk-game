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

	//Displays the different possible actions in the phase
	switch(a){
		case 0:
			cout << playerName << ": Attack Phase" << endl;
			break;
		case 1:
			cout << playerName << " ends their attack phase" << endl;
			break;
		case 2:
			cout << playerName <<  " attacks" << endl;
			break;
		case 3:
			if (conquered){
				cout << playerName << " has conquered " << defendName << endl;
			}
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

void GameView::updateFortify(int f, string a, string b, int m){
	
		displayFortify(f, a, b, m);
	  
}

void GameView::displayFortify(int f, string a, string b, int m){
	string playerName = _subject->name;
	switch(f){
		case 0:
			cout <<playerName << "ends their fortify phase " << endl;
			break;
		case 1:
			cout << playerName << " fortifies " << b << " with " << m << " armies."<< endl;
			break;
		case 2:
			cout << playerName << ": Fortification Phase." << endl;
	}
}
void GameView::updateReinforce(int r, int p, string where){
	
		displayReinforce(r, p, where);
	  
}

void GameView::displayReinforce(int r, int p, string where){
	string playerName = _subject->name;
	switch(r){
		case 0:
			cout << playerName << " ends their reinforce phase " << endl;
			break;
		case 1:
			cout << playerName << " reinforces " << where << " with " << p << " armies." <<endl;
			break;
		case 2:
			cout << playerName << " has to exchange cards." << endl;
			break;
		case 3:
			cout << playerName << ": Reinforcement Phase" <<endl;
			break;
	}
}


