#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <list>
using namespace std;

class Observer;
class Subject{

public:
    virtual void Attach(Observer* O);
    virtual void Detach(Observer* O);
    virtual void Notify();
    virtual void NotifyAttack(int a);
    virtual void NotifyReinforce(int);
    virtual void NotifyFortify(int);

    Subject();
    ~Subject();
private:
    list <Observer*> *_observers;
    
};

#endif