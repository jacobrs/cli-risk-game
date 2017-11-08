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


void GameView::updateAttack(int a){
	
		displayAttack(a);
	  
}

void GameView::displayAttack(int a){
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
		/*
		cout << attackCountry->owner->name << "\'s country " << attackCountry->name << " now has " << attackCountry->armies << " armies." << endl;
		cout << defendCountry->owner->name << "\'s country " << defendCountry->name << " now has " << defendCountry->armies << " armies." << endl;
		cout << attackCountry->owner->name << (ownsAttackCountry(map)?" can":" cannot") << " attack again." << endl;
		
		*/
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


