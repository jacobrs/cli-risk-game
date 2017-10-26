#include "../headers/MapLoader.h"
#include "../headers/Continent.h"
#include "../headers/Country.h"
#include "../headers/GameMap.h"

#include <stdio.h>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

MapLoader::MapLoader(const char* filePath){ /*File path is location of the game map to be imported*/
	mapPath = filePath;
	isValid = true;
}
MapLoader::~MapLoader(){
	mapContinents.clear();
	mapCountries.clear();
}

static ifstream mapFile;

void MapLoader::importMap(){ 
	string path(mapPath);
	string mapLine = "";
	bool readingContinents = false; //bool to keep track when entering continents section
	bool readingCountries = false; //bool to keep track when entering countries section
	bool readingNeighbours = false; 
	
	mapFile.open(mapPath, std::ifstream::in);//open file stream

	if(mapFile.is_open()){ //check stream is open
		while(!mapFile.eof()){ //while end of file is not reached
			getline(mapFile, mapLine); //get next line from map file
			if(mapLine.find("[Continents]") != string::npos){ //if entering continents section of map file
				readingContinents = true;
				continue;
			}
			else if(mapLine.find("[Territories]") != string::npos){ //if entering country section of map file
				readingCountries = true;
				continue;
			}

			if(readingCountries && strlen(mapLine.c_str())>1){ //check if there was territories section and line is not empty
				importCountry(mapLine);
			}
			else if(readingContinents && !readingCountries && strlen(mapLine.c_str())>1){ //check if there was continents section and line is not empty
				importContinent(mapLine);
			}
		}

		if(!readingContinents || !mapContinents.size()){
			isValid = false;
			printf("MAP FILE INVALID: DOES NOT CONTAIN CONTINENTS.\n");
			mapFile.close();
			return;
		}
		if(!readingCountries || !mapCountries.size()){
			isValid = false;
			printf("MAP FILE INVALID: DOES NOT CONTAIN COUNTRIES.\n");
			mapFile.close();
			return;
		}
		mapFile.close();
	}
	else{
		printf("File: \"%s\" NOT FOUND.\n", mapPath);
		return;
	}

	mapFile.open(mapPath, std::ifstream::in);//reopen file stream to import neighbours

	if(mapFile.is_open()){ //check stream is open
		while(!mapFile.eof()){ //while end of file is not reached
			getline(mapFile, mapLine); //get next line from map file
			if(mapLine.find("[Territories]") != string::npos){ //if entering country section of map file
				readingNeighbours = true;
				continue;
			}

			if(readingNeighbours && strlen(mapLine.c_str())>1){ //check if there was territories section and line is not empty
				importNeighbours(mapLine);
			}
		}
		mapFile.close();
	}
}

void MapLoader::importContinent(string continentString){
	try{
		string continentName = continentString.substr(0, continentString.find("=")).c_str();
		int continentBonus = stoi(continentString.substr(continentString.find("=")+1, continentString.size()).c_str());
		Continent* newContinent = new Continent(continentName.c_str(), continentBonus);
		mapContinents.push_back(newContinent);
	}
	catch(...){
		isValid = false;
		printf("\nERROR OCCURED WHILE READING CONTINENTS, CHECK .map FILE\n");
	}
}

void MapLoader::importCountry(string countryString){
	std::istringstream ss(countryString);
	string countryName;
	string continentName;
	string bitmapA, bitmapB;
	getline(ss, countryName, ','); //get name before first comma
	getline(ss, bitmapA, ','); // bitmap locations
	getline(ss, bitmapB, ','); // bitmap locations
	getline(ss, continentName, ',');
	Country* newCountry = new Country(countryName.c_str());
	mapCountries.push_back(newCountry);
	for(unsigned i = 0; i < mapContinents.size(); i++){
		if(mapContinents[i]->name.find(continentName) != string::npos && mapContinents[i]->name.length() == continentName.length()){ // this country is part of this continent
			mapContinents[i]->addCountry(newCountry);
		}
	}
}

void MapLoader::importNeighbours(string countryString){
	countryString.replace(countryString.end()-1, countryString.end(), '\n', ',');
	std::istringstream ss(countryString);
	string countryName;
	string neighbourName;
	string continentName;
	string bitmapA, bitmapB;
	getline(ss, countryName, ','); //get name before first comma
	getline(ss, bitmapA, ','); // bitmap locations
	getline(ss, bitmapB, ','); // bitmap locations
	getline(ss, continentName, ',');

	unsigned countryIndex = 0;
	for(; countryIndex < mapCountries.size(); countryIndex++){ // find country index
		if(mapCountries[countryIndex]->name.find(countryName) != string::npos && mapCountries[countryIndex]->name.length() == countryName.length()){ 
			break;
		}
	}
	while(getline(ss, neighbourName, ',')){ // add all neighbours
		 //get next neighbour name
		for(unsigned i = 0; i < mapCountries.size(); i++){
			if(mapCountries[i]->name.find(neighbourName) != string::npos && mapCountries[i]->name.length() == neighbourName.length()){
				mapCountries[countryIndex]->addNeighbour(mapCountries[i]);
			}
		}
	}
}

GameMap* MapLoader::exportToGameMap(){
	GameMap* world = new GameMap();
	for(unsigned i = 0; i < this->mapContinents.size(); i++){
		Continent* tempCon = this->mapContinents[i];
		world->addContinent(tempCon);
	}
	return world;
}
