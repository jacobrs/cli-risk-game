#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "Observer.h"
#include "Subject.h"
#include "Player.h"
#include "GamePlay.h"

class GameView : public Observer {

public:
    GameView();
    GameView(GamePlay* gp);
    ~GameView();
    void update() override;
    void display();

private:
    GamePlay* _subject;
};

#endif 