#include "../headers/GameSubject.h"
#include "../headers/GameStateObserver.h"

GameSubject::GameSubject(){
    _observers = new list<GameStateObserver*>;
};

GameSubject::~GameSubject(){
    delete _observers;
};

void GameSubject::Attach(GameStateObserver* o){
    _observers -> push_back(o);
};

void GameSubject::Detach(GameStateObserver* o){
    _observers -> remove(o);
};

void GameSubject::Notify(GameMap* map, vector<Player*> players, int turns){
    list<GameStateObserver*>::iterator i = _observers->begin();
    for(; i != _observers->end(); ++i){
        (*i)->updateState(map, players, turns);
    }
}
