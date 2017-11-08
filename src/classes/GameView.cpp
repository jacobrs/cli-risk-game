#include "../headers/GameView.h"
#include <iostream>

using namespace std;

GameView::GameView(){

}

/*
GameView::~GameView(){
    for each (Player* p1 in _subjects)
	{
		delete p1;
		p1 = nullptr;
	}
	_subject->Detach(this);
}
*/
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

	if (a == 0){
		cout << player->name << " can't attack because you don't own a country that can attack" << endl;
	} else if (a == 1) {

	} else {

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


