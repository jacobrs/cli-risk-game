#include "../headers/HumanPlayer.h"
#include <iostream>

using namespace std;

void HumanPlayer::execute(Player *player, GameMap* map){
    cout<< "Human Player"<< endl;
    player->reinforce(map);
    player->attack(map);
    
    //human interaction required
    cout<<"Fortification phase:\n\n";
    player->getStrongetCountry(map);
    cout<<"Please Choose a country to move armies from: "<<endl;
    string fromC = "";
    cin>>fromC;
    Country* fromCountry = map->getCountryByName(fromC);
    while(fromCountry == NULL){
        cout<<"INVALID INPUT PLEASE CHOOSE ONE OF THE CONTRIES LISTED"<<endl;
        player->getStrongetCountry(map);
        fromC = "";
        cin>>fromC;
        fromCountry = map->getCountryByName(fromC);
    }
    cout<<"Please Choose a country to move armies to: "<<endl;
    string toC = "";
    cin>>toC;
    Country* toCountry = map->getCountryByName(toC);
    while(toCountry == NULL){
        cout<<"INVALID INPUT PLEASE CHOOSE ONE OF THE CONTRIES LISTED"<<endl;
        player->getStrongetCountry(map);
        toC = "";
        cin>>toC;
        toCountry = map->getCountryByName(toC);
    }
    cout<<"Please enter a number of armies to move. You can move up to "<< fromCountry->armies << " armies"<< endl;
    int number = 0;
    cin>>number;
    while(cin.fail() || number < 0 || number > fromCountry->armies){//just in case user can't read
        cout << "INVALID INPUT, ";
        cout<<"Please enter a number of armies to move. You can move up to "<< fromCountry->armies << " armies"<< endl;
        cin >> number;
    }
    player->fortify(fromCountry, toCountry, number);
    
}
HumanPlayer::~HumanPlayer(){}