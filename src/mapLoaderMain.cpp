#include "headers/MapLoader.h"
#include "headers/Continent.h"
#include "headers/Country.h"
#include "headers/GameMap.h"
#include "headers/Player.h"

using namespace std;

int main(int args, char** argv){

    printf("\n\nEXPECTING FILE NOT FOUND:\n");
    MapLoader* fileNotFound = new MapLoader("map/BEEPBEEP.map");
    fileNotFound->importMap();
    fileNotFound->~MapLoader();

    printf("\n\nEXPECTING MAP FILE THAT DOES NOT CONTAIN CONTINENTS:\n");
    MapLoader* noContinent = new MapLoader("map/noContinent.map");
    noContinent->importMap();
    noContinent->~MapLoader();

    printf("\n\nEXPECTING MAP FILE THAT DOES NOT CONTAIN COUNTRIES:\n");
    MapLoader* noCountry = new MapLoader("map/noCountry.map");
    noCountry->importMap();
    noCountry->~MapLoader();

    printf("\n\nEXPECTING CORRECT FILE PATH AND FILE FORMAT:\n");
    MapLoader* mapLoader = new MapLoader("map/World.map");
    mapLoader->importMap();
    GameMap* world = new GameMap();

    printf("\n\nLIST ALL CONTINENTS AND THEIR BONUS VALUES AND COUNTRIES\n");
    for(unsigned i = 0; i < mapLoader->mapContinents.size(); i++){
        Continent* tempCon = mapLoader->mapContinents[i];
        world->addContinent(tempCon);
        printf("\n%s", tempCon->name.c_str());
        printf("\t%i", tempCon->bonus);
        for(unsigned j = 0; j < tempCon->numberOfCountries; j++){
            printf("\t%s", tempCon->countries[j]->name.c_str());
        }
    }

    printf("\n\nLIST ALL COUNTRIES AND THEIR NEIGHBOURS:\n");
    for(unsigned i = 0; i < mapLoader->mapCountries.size(); i++){
        printf("\n%s", mapLoader->mapCountries[i]->name.c_str());
        for(unsigned j = 0; j < mapLoader->mapCountries[i]->numberOfNeighbours; j++){
            printf("\t%s",  mapLoader->mapCountries[i]->neighbours[j]->name.c_str());
        }
    }

    printf("\n\nTESTING (WORLD):\n");
    world->isValidMap();
    mapLoader->~MapLoader();
    world->~GameMap();

    printf("\n\nEXPECTING CORRECT FILE PATH AND FILE FORMAT (KHORAS):\n");
    MapLoader* khorasLoader = new MapLoader("map/Khoras.map");
    khorasLoader->importMap();
    GameMap* khoras = new GameMap();

    printf("CREATE GAMEMAP WITH IMPORTED FILE AND TESTING (KHORAS):\n");
    for(unsigned i = 0; i < khorasLoader->mapContinents.size(); i++){
        Continent* tempCon = khorasLoader->mapContinents[i];
        khoras->addContinent(tempCon);
    }

    printf("\n\nLIST ALL COUNTRIES AND THEIR NEIGHBOURS (KHORAS):\n");
    for(unsigned i = 0; i < khorasLoader->mapCountries.size(); i++){
        printf("\n%s", khorasLoader->mapCountries[i]->name.c_str());
        for(unsigned j = 0; j < khorasLoader->mapCountries[i]->numberOfNeighbours; j++){
            printf("\t%s",  khorasLoader->mapCountries[i]->neighbours[j]->name.c_str());
        }
    }

    printf("\n\nTESTING (KHORAS):\n");
    khoras->isValidMap();
    khorasLoader->~MapLoader();
    khoras->~GameMap();
}
