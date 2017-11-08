#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "Observer.h"
#include "Player.h"


class GameView : public Observer {

public:
    GameView();
    GameView(Player* p);
    ~GameView();
    void update() override;
    void updateAttack(int a) override;
    void updateReinforce(int r) override;
    void updateFortify(int f) override;
    void display();
    void displayAttack(int a);
    void displayReinforce(int r);
    void displayFortify(int f);

private:
    Player *_subject;
};

#endif