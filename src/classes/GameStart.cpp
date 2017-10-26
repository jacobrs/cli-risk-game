#include "../headers/GameStart.h"

#include <string>
#include <iostream>

using namespace std;

GameStart::GameStart(){
}

GameStart::~GameStart(){
    delete GameStart;
}

GameStart::GameStart(string map, int nbPlayers){
    MapLoader(selectedMap);
    numOfPlayers = nbPlayers;
    createPlayers(nbPlayers);
    //get number of countries in the map
    createDeck(numCountries);
}

GameStart::createPlayers(int nbPlayers){

    enterPlayer = true;

    for (int i = 0; i < nbPlayers; i++){
        while(enterPlayer){
            string playerName = "";
            string playerColour = "";
            cout << "Player name: ";
            cin >> playerName;
            cout << "\nPlayer colour: ";
            cin >> playerColour;
        }
        Player newPlayer = Player();
        this -> players.push_back(newPlayer);

    }
}

int GameStart::getNumOfPlayers(){
    return numOfPlayers;
}