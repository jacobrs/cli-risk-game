/* 
#include "headers/StartupPhase.h"
#include "headers/GameStart.h"
#include "headers/Player.h"
#include <string>

using namespace std;

int main(){

    string selectedMap;
    int numOfPlayers = 0;
    bool promptPlayers = true;
    bool promptMap = true;
    vector <Player> players;
       

        cout << "Number of Players between 2-6: " << endl;
        cin >> numOfPlayers;
        cout << "Select Map File: Khoras or World" << endl;
        cin >> selectedMap;

        StartupPhase* start = new StartupPhase(selectedMap, numOfPlayers);

   
    return 0;
}
*/