#include "headers/GameStart.h"
#include "headers/MapLoader.h"
#include "headers/Player.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string selectedMap;
    int numOfPlayers = 0;
    bool promptPlayers = true;
    bool promptMap = true;
    
       

    while (promptPlayers){
        cout << "Number of Players between 2-6: " << endl;
        cin >> numOfPlayers;

        if (numOfPlayers < 2 || numOfPlayers >6){ 
            cout << "Please enter correct number of players" << endl;
           } 
        else{
            promptPlayers =false;
        }
    }

    while (promptMap){
        cout << "Select Map File: Khoras.map, noContinent.map, noCountry.map or World.map" << endl;
        cin >> selectedMap;

        if (selectedMap.compare("Khoras.map") == 0 || selectedMap.compare("World.map") == 0){ 
            promptMap =false;

           } 
        else{
            cout << "Please enter the correct filename" << endl;
        }
    }
  

    GameStart newGame = GameStart(selectedMap, numOfPlayers);

    return 0;
    
}