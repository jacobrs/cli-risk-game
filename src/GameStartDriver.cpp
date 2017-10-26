#include "headers/GameStart.h"
#include "headers/MapLoader.h"
#include "headers/Player.h"
#include <iostream>
#include <string>

using namespace std;


int main(){

    string selectedMap = "";
    int numOfPlayers = 0;
    bool chekInput = true;

    while(checkInput){    
        cout << "Select Map File: Khoras.map, noContinent.map, noCountry.map or World.map" << endl;
        cin >> selectedMap;
        cout << "Number of Players between 2-6: " << endl;
        cin >> numOfPlayers;

        if (numOfPlayers < 0 && numOfPlayers >7){ 
            cout << "Please enter correct number of players" << endl;
        } else if (seletedMap.compare("Khoras.map") || seletedMap.compare("noContinent.map") || seletedMap.compare("World.map")){ 
            cout << "Please enter the correct filename" << endl;
        } else{
            checkInput = false;
        }
    }

    GameStart::GameStart(seletedMap, numOfPlayers);


    return 0;
}