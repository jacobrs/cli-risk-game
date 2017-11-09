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
    void updateAttack(int a, string attackName, string defendName, int aa, int da, bool conquered) override;
    void updateReinforce(int r, int p,  string where) override;
    void updateFortify(int f, string a, string b, int m) override;
    void display();
    void displayAttack(int a, string attackName, string defendName, int aa, int da, bool conquered);
    void displayReinforce(int r, int p,  string where);
    void displayFortify(int f, string a, string b, int m);

private:
    Player *_subject;
};

#endif