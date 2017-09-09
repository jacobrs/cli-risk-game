#include "../headers/Country.h"

using namespace std;

Country::Country(string countryName){
  armies = 0;
  name = countryName;
  numberOfNeighbours = 0;
}

Country::Country(){
  Country::Country("");
}

void Country::addNeighbour(Country newNeighbour){
  // Create a new array of size current + 1
  Country *newCountries = new Country[++numberOfNeighbours];
  // and populate it with the old neighbours
  for(int i = 0; i < numberOfNeighbours - 1; i++){
    newCountries[i] = neighbours[i];
  }
  // add the new neighbour to the list
  newCountries[numberOfNeighbours - 1] = newNeighbour;
  
  // and overwrite the old neighbours with the new
  if(numberOfNeighbours > 0)
    delete [] neighbours;
  
  neighbours = newCountries;
}

Country::~Country(){
  // Must delete the pointers to neighbours
  // in order to avoid memory leaks
  if(numberOfNeighbours > 0)
    delete [] neighbours;
}
