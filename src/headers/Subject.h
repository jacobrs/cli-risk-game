#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <string>
#include <list>
using namespace std;

class Observer;
class Subject{

public:
    virtual void Attach(Observer* O);
    virtual void Detach(Observer* O);
    virtual void Notify();
    virtual void NotifyAttack(int a, string attackName, string defendName, int aa, int da, bool conquered);
    virtual void NotifyReinforce(int r, int p, string where);
    virtual void NotifyFortify(int f, string a, string b, int m);

    Subject();
    ~Subject();
private:
    list <Observer*> *_observers;
    
};

#endif
