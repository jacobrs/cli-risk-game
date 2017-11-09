#include "../headers/GameObserver.h"
#include "../headers/Player.h"
#include <iostream>
using namespace std;

GameObserver::GameObserver(){

};
GameObserver::GameObserver(Player* p){
    //Upon instantiation, attaches itself to a Player
    _subject = p;
    _subject->Attach(this);
}(

GameObserver::~GameObserver(){
    //Upon destruction, detaches itself from its Player
    _subject->Detach(this);
}

void GameObserver::Update(){
    display();
}

void GameObserver::display(){

}

void GameObserver::UpdateAttack(){
    displayAttack();
}

void GameObserver::displayAttack(){
    
}

void GameObserver::UpdateReinforce(){
    displayReinforce();
}

void GameObserver::displayReinforce(){
    
}

void GameObserver::UpdateFortify(){
    displayFortify();
}

void ameObserver::displayFortify(){
    
}