#include "headers/GameStart.h"
#include "headers/MapLoader.h"
#include "headers/Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    string selectedMap;
    int numOfPlayers = 0;
    bool promptPlayers = true;
    bool promptMap = true;
    vector <Player> players;
       
    // Validates the number of players
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
    //validates the map chosen
    while (promptMap){
        cout << "Select Map File: Khoras or World" << endl;
        cin >> selectedMap;

        if (selectedMap.compare("Khoras") == 0 || selectedMap.compare("World") == 0){ 
            promptMap =false;

           } 
        else{
            cout << "Please enter the correct filename" << endl;
        }
    }
  
    GameStart* newGame = new GameStart(selectedMap, numOfPlayers);

    cout << "Amount of players: " << newGame -> players.size() << endl;

    cout << "Bye";


    return 0;
    
}