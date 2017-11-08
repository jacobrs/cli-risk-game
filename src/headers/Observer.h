#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"

class Subject;

class Observer{

public:
    ~Observer();
    virtual void update() = 0;
    virtual void updateAttack(int a) = 0;
    virtual void updateReinforce(int r) = 0;
    virtual void updateFortify(int f) = 0;
    
protected:
    Observer();

};

#endif
