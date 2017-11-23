#include "../headers/GameSubject.h"
#include "../headers/GameStateObserver.h"
#include "../headers/HandObserverDecorator.h"
#include "../headers/CountryObserverDecorator.h"
#include "../headers/ContinentObserverDecorator.h"

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

void GameSubject::Notify(GameMap* map, vector<Player*> players){
    list<GameStateObserver*>::iterator i = _observers->begin();
    for(; i != _observers->end(); ++i){
        if(dynamic_cast<CountryObserverDecorator*>(*i) != nullptr){
            (dynamic_cast<CountryObserverDecorator*>(*i))->updateState(map, players);
        }else if(dynamic_cast<HandObserverDecorator*>(*i) != nullptr){
            (dynamic_cast<HandObserverDecorator*>(*i))->updateState(map, players);
        }else if(dynamic_cast<ContinentObserverDecorator*>(*i) != nullptr){
            (dynamic_cast<ContinentObserverDecorator*>(*i))->updateState(map, players);
        }else{
            (*i)->updateState(map, players);
        }
    }
}
