#include "headers/MapLoader.h"
#include "headers/Continent.h"
#include "headers/Country.h"
#include "headers/GameMap.h"

using namespace std;

int main(int args, char** argv){

    printf("\n\nEXPECTING FILE NOT FOUND:\n");
    MapLoader* fileNotFound = new MapLoader("src/map/BEEPBEEP.map");
    fileNotFound->importMap();

    printf("\n\nEXPECTING MAP FILE THAT DOES NOT CONTAIN CONTINENTS:\n");
    MapLoader* noContinent = new MapLoader("src/map/noContinent.map");
    noContinent->importMap();

    printf("\n\nEXPECTING MAP FILE THAT DOES NOT CONTAIN COUNTRIES:\n");
    MapLoader* noCountry = new MapLoader("src/map/noCountry.map");
    noCountry->importMap();

    printf("\n\nEXPECTING CORRECT FILE PATH AND FILE FORMAT:\n");
    MapLoader* mapLoader = new MapLoader("src/map/World.map");
    mapLoader->importMap();

    printf("List all continents and their bonus value and countries:\n");
    for(unsigned i = 0; i < mapLoader->mapContinents.size(); i++){
        Continent* tempCon = mapLoader->mapContinents[i];
        printf("\n%s", tempCon->name.c_str());
        printf("\t%i", tempCon->bonus);
        for(unsigned j = 0; j < tempCon->numberOfCountries; j++){
            printf("\t%s", tempCon->countries[j]->name.c_str());
        }
    }
    
    printf("List all countries and their neighbours:\n");
    for(unsigned i = 0; i < mapLoader->mapCountries.size(); i++){
        printf("\n%s", mapLoader->mapCountries[i]->name.c_str());
        for(unsigned j = 0; j < mapLoader->mapCountries[i]->numberOfNeighbours; j++){
            printf("\t%s",  mapLoader->mapCountries[i]->neighbours[j]->name.c_str());
        }
    }

    printf("\n\nEXPECTING CORRECT FILE PATH AND FILE FORMAT:\n");
    MapLoader* khorasLoader = new MapLoader("src/map/Khoras.map");
    khorasLoader->importMap();

    printf("List all continents and their bonus value and countries:\n");
    for(unsigned i = 0; i < khorasLoader->mapContinents.size(); i++){
        Continent* tempCon = khorasLoader->mapContinents[i];
        printf("\n%s", tempCon->name.c_str());
        printf("\t%i", tempCon->bonus);
        for(unsigned j = 0; j < tempCon->numberOfCountries; j++){
            printf("\t%s", tempCon->countries[j]->name.c_str());
        }
    }
    
    printf("List all countries and their neighbours:\n");
    for(unsigned i = 0; i < khorasLoader->mapCountries.size(); i++){
        printf("\n%s", khorasLoader->mapCountries[i]->name.c_str());
        for(unsigned j = 0; j < khorasLoader->mapCountries[i]->numberOfNeighbours; j++){
            printf("\t%s",  khorasLoader->mapCountries[i]->neighbours[j]->name.c_str());
        }
    }
}
