#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"
#include <string>

using namespace std;

class Subject;

class Observer{

public:
    ~Observer();
    virtual void update() = 0;
    virtual void updateAttack(int a, string attackName, string defendName, int aa, int da, bool conquered) = 0;
    virtual void updateReinforce(int r) = 0;
    virtual void updateFortify(int f) = 0;
    
protected:
    Observer();

};

#endif
