#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

using namespace std;

class Observer{

public:
    ~Observer();
    virtual void update() = 0;
    virtual void updateAttack(int a, string attackName, string defendName, int aa, int da, bool conquered) = 0;
    virtual void updateReinforce(int r, int p, string where) = 0;
    virtual void updateFortify(int f, string a, string b, int m) = 0;
    Observer();

};

#endif
