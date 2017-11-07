#include "../headers/GameView.h"

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
GameView::GameView(GamePlay* gp){
    _subject = gp;
    _subject->Attach(this);
}

void GameView::update(){

    display();
  
}

void GameView::display(){

}

