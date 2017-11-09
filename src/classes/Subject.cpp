#include "../headers/Subject.h"
#include "../headers/Observer.h"

Subject::Subject(){
    _observers = new list<Observer*>;
};

Subject::~Subject(){
    delete _observers;
};

void Subject::Attach(Observer* o){
    _observers -> push_back(o);
};

void Subject::Detach(Observer* o){
    _observers -> remove(o);
};

void Subject::Notify(){
    list<Observer*>::iterator i = _observers->begin();
    for(; i != _observers->end(); ++i){
        (*i)->update();    
    }
};

void Subject::NotifyAttack(int a, string attackName, string defendName, int aa, int da, bool conquered){
    list<Observer*>::iterator i = _observers->begin();
    for(; i != _observers->end(); ++i){
        (*i)->updateAttack(a, attackName, defendName, aa, da, conquered);    
    }
};

void Subject::NotifyReinforce(int r){
    list<Observer*>::iterator i = _observers->begin();
    for(; i != _observers->end(); ++i){
        (*i)->updateReinforce(r);    
    }
};
void Subject::NotifyFortify(int f){
    list<Observer*>::iterator i = _observers->begin();
    for(; i != _observers->end(); ++i){
        (*i)->updateFortify(f);    
    }
};
