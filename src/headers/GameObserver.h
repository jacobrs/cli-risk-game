#pragma once 
#include "Observer.h"
#include "Player.h"

class GameObserver: public Observer{
public:
    GameObserver();
    GameObserver(Player* p);
    ~GameObserver();

    void Update();
    void UpdateAttack();
    void UpdateReinforce();
    void UpdateFortify();
    void display();
    void displayAttack();
    void displayReinforce();
    void displayFortify();

private:
    Player *_subject;

};