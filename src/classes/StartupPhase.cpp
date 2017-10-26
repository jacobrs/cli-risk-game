#import "..headers/StartupPhase.h"

StartupPhase::StartupPhase(){
}

StartupPhase::~StartupPhase(){
    delete StartupPhase();
}

StartupPhase::StartupPhase(mapPlaying, numPlayers){
    map = mapPlaying;
    nbPlayers = numPlayers;

    shufflePlayers();
    
    switch (numPlayers){
        case(2):
            armiesStart = 40;
            break;
        case(3):
            armiesStart = 35;
            break;
        case(4):
            armiesStart = 30;
        break;
        case(5):
            armiesStart = 25;
            break;
        case(6):
            armiesStart = 20;
            break;
        default:
            break;
    }

}

void StartupPhase::shufflePlayers(){
    random_device rd;
    mt19937 g(rd());

	shuffle(players.begin(), players.end(), g);
}

