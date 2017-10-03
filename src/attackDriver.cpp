#include "headers/Player.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int args, char** argv){
    srand (time(NULL));
    
    Player *player1 = new Player(0,"Katia", "red", 2);
    Player *player2 = new Player(0, "Darrin", "green", 2);
    Country *canada = new Country("Canada");
    Country *usa = new Country("USA");
    Country *mexico = new Country("Mexico");
    Country *guatemala = new Country("Guatemala");
    Country *honduras = new Country("Honduras");

    string country = "";
    Country *attackingCountry = new Country("");
    Country *attackedCountry = new Country("");

    Country **countryCatalog = new Country*[5];
    countryCatalog[0] = canada;
    countryCatalog[1] = usa;
    countryCatalog[2] = mexico;
    countryCatalog[3] = guatemala;
    countryCatalog[4] = honduras;

    int numberOfCountries = 5;
    canada->owner = player1;
    usa->owner = player1;
    mexico->owner = player2;
    guatemala->owner = player2;
    honduras->owner = player2;

    canada->addNeighbour(usa);
    usa->addNeighbour(canada);
    mexico->addNeighbour(usa);
    mexico->addNeighbour(guatemala);
    guatemala->addNeighbour(honduras);

        

    cout<< player1->name<<" choose one of your available countries: ";
    for(int i = 0; i < numberOfCountries; i++){
        cout<< countryCatalog[i]->name<< ", ";
    }
    cin>> country;
    for(int i = 0; i < numberOfCountries; i++){
        if(country == countryCatalog[i]->name) 
            attackingCountry = countryCatalog[i];
    }
    if(attackingCountry->name != ""){
        country = "";
        cout<<"\n Countries available to be attack:";
        int selfNeighbours = 0;
        for(int i = 0; i < attackingCountry->numberOfNeighbours; i++){
            if(attackingCountry->neighbours[i]->owner->name != attackingCountry->owner->name)
                cout<< attackingCountry->neighbours[i]->name<< ", ";
            else{selfNeighbours++;}
        }
        if (selfNeighbours != attackingCountry->numberOfNeighbours){
            cout<<"\nEnter the name of the country you wish to attack: ";
            cin>> country;
            for(int i = 0; i < attackingCountry->numberOfNeighbours; i++){
                if(country == attackingCountry->neighbours[i]->name) 
                    attackedCountry = attackingCountry->neighbours[i];
            }
            if(attackedCountry->name != ""){
                player1->attack(attackingCountry, attackedCountry);
            }
            else cout<< "\nThe country you want to attack is not a neighbour of "<<attackingCountry->name << ". Try again";
        }
        else cout<<"\n No available countries to attack";
    }
    else cout<<"\nThe country you chose is unavailable try again later";
}