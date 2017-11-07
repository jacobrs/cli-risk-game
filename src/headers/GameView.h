#ifdef GAMEVIEW_H
#define GAMEVIEW_H

#include "Observer.h"
#include "Subject.h"
#include "Player.h"

class GameView : public Observer {

public:
    GameView();
    ~GameView();

};

#endif 