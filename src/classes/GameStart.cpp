#include "../headers/GameStart.h"
#include "../headers/MapLoader.h"
#include "../headers/GameMap.h"
#include "../headers/Deck.h"


#include <string>
#include <iostream>
#include <vector>

using namespace std;

GameStart::GameStart(){
    numOfPlayers =0;
    map = "";
    deckSize =0;
}


GameStart::GameStart(string mapChosen, int nbPlayers){

    //creating the players
    numOfPlayers = nbPlayers;
    createPlayers(nbPlayers);
    MapLoader* playMap;

    //Getting the map chosen
    if(mapChosen.compare("Atlantis") == 0){
        playMap = new MapLoader("map/Atlantis.map");
        playMap->importMap();
        gameMap = playMap->exportToGameMap();
        printf("Checking integrity of game map\n\n");
        gameMap->isValidMap();
    } else if (mapChosen.compare("Dice") == 0){
        playMap = new MapLoader("map/Dice.map");
        playMap->importMap();
        gameMap = playMap->exportToGameMap();
        printf("Checking integrity of game map\n\n");
        gameMap->isValidMap();
    }else if (mapChosen.compare("Khoras") == 0){
        playMap = new MapLoader("map/Khoras.map");
        playMap->importMap();
        gameMap = playMap->exportToGameMap();
        printf("Checking integrity of game map\n\n");
        gameMap->isValidMap();
    } else if (mapChosen.compare("Swamp") == 0){
        playMap = new MapLoader("map/Swamp.map");
        playMap->importMap();
        gameMap = playMap->exportToGameMap();
        printf("Checking integrity of game map\n\n");
        gameMap->isValidMap();
    }else if (mapChosen.compare("World") == 0){
        playMap = new MapLoader("map/World.map");
        playMap->importMap();
        gameMap = playMap->exportToGameMap();
        printf("Checking integrity of game map\n\n");
        gameMap->isValidMap();
    }else{
        cout << "Error" << endl;
    }

    deckSize = playMap -> mapCountries.size();

    //creates the Deck (num of cards has to be equal to num of Countries)
    Deck* playDeck = new Deck(deckSize);

    //Check the number of cards and countries
    cout << "\nNumber of Countries: " << playMap -> mapCountries.size() << endl;
    cout << "Deck size: " << playDeck -> getSize() << endl;
}


void GameStart::createPlayers(int nbPlayers){

    //players.reserve(nbPlayers);

    cout << "\nPlayers information: "<< endl;
    //creates the different players
    for (int i = 0; i < nbPlayers; i++)
    {
            string playerName = "";
            string playerColour = "";
            cout << "Player name: ";
            cin >> playerName;
            cout << "Player colour: ";
            cin >> playerColour;

        Player *newPlayer = new Player(i, playerName, playerColour);
       this -> players.push_back(newPlayer);
    }
}
GameStart::~GameStart(){
    delete gameMap;
    gameMap = NULL;
    for(int i = 0; i < players.size(); i++){
        delete players[i];
        players[i] = NULL;
    }
}
