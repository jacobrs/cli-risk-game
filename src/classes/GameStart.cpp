#include "../headers/GameStart.h"

#include <string>
#include <iostream>

using namespace std;

GameStart::GameStart(){
    numOfPlayers =0;
    map = "";
}


GameStart::GameStart(string mapPlay, int nbPlayers){
   // seletedMap = MapLoader(map);
    numOfPlayers = nbPlayers;
    map = mapPlay;
    createPlayers(numOfPlayers);
    //get number of countries in the map
  //  createDeck(numCountries);
}

void GameStart::createPlayers(int nbPlayers){

    //enterPlayer = true;

    for (int i = 0; i < nbPlayers; i++){
        //while(enterPlayer){
            string playerName = "";
            string playerColour = "";
            cout << "Player name: ";
            cin >> playerName;
            cout << "\nPlayer colour: ";
            cin >> playerColour;
        //}
        Player newPlayer = Player(i, playerName, playerColour);
        this -> players.push_back(newPlayer);
       // players[i] = newPlayer;


    }
}

int GameStart::getNumOfPlayers(){
    return numOfPlayers;
}