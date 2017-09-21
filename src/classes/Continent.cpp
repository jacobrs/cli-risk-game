#include "../headers/Continent.h"

using namespace std;

Continent::Continent(string continentName, int bonusValue){
  bonus = bonusValue;
  name = continentName;
  numberOfCountries = 0;
}

Continent::Continent(){
  Continent::Continent("", 0);
}

void Continent::addCountry(Country* newCountry){
  
  bool alreadyElement = false;

  // Create a new array of size current + 1
  Country **newCountries = new Country*[++numberOfCountries];
  // and populate it with the old countries
  for(int i = 0; i < numberOfCountries - 1; i++){
    newCountries[i] = countries[i];
    if(countries[i]->name == newCountry->name){
      alreadyElement = true;
      break;
    }
  }

  // add the new neighbour to the list if not already neighbours
  if(!alreadyElement){
    newCountries[numberOfCountries - 1] = newCountry;
    // and make sure that the new neighbour knows its a neighbour    
    countries = newCountries;
  }else{
    numberOfCountries--;
  }

}
