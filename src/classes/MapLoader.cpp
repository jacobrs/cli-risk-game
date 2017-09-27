#include "../headers/MapLoader.h"
#include "../headers/Continent.h"
#include "../headers/Country.h"

#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

MapLoader::MapLoader(const char* filePath){ /*File path is location of the game map to be imported*/
	mapPath = filePath;
	isValid = true;
}

static ifstream mapFile;

void MapLoader::importMap(){ 
	/*Returns false if map is invalid (not in the standard .map format)
		Map format: 
		[Continents]
		continent=capture points

		[Territories]
		name, IGNORE, IGNORE, continent, neighbours...
	*/
	string path(mapPath);
	string mapLine = "";
	bool readingContinents = false; //bool to keep track when entering continents section
	bool readingCountries = false; //bool to keep track when entering countries section
	
	mapFile.open(mapPath, std::ifstream::in);//open file stream

	if(mapFile.is_open()){ //check stream is open
		while(!mapFile.eof()){ //while end of file is not reached
			getline(mapFile, mapLine); //get next line from map file
			if(!mapLine.compare("[Continents]")){ //if entering continents section of map file
				readingContinents = true;
				continue;
			}
			else if(!mapLine.compare("[Territories]")){ //if entering country section of map file
				readingCountries = true;
				continue;
			}

			if(readingCountries && mapLine.compare("")){
				//importCountry(mapLine);
			}
			else if(readingContinents && !readingCountries && mapLine.compare("")){
				importContinent(mapLine);
			}
		}

		if(!readingContinents || !mapContinents.size()){
			isValid = false;
			printf("MAP FILE INVALID: DOES NOT CONTAIN CONTINENTS.\n");
		}
		if(!readingCountries || !mapCountries.size()){
			isValid = false;
			printf("MAP FILE INVALID: DOES NOT CONTAIN COUNTRIES.\n");
		}
		mapFile.close();
	}
	else{
		printf("File: \"%s\" NOT FOUND.\n", mapPath);
	}
}

void MapLoader::importContinent(string continentString){
	try{
		string continentName = continentString.substr(0, continentString.find("=")).c_str();
		int continentBonus = atoi(continentString.substr(continentString.find("=")+1, continentString.size()).c_str());
		const Continent* newContinent = new Continent(continentName.c_str(), continentBonus);
		mapContinents.push_back(*newContinent);
	}
	catch(...){
		isValid = false;
		printf("ERROR OCCURED WHILE READING CONTINENTS, CHECK .map FILE\n");
	}
}

void MapLoader::importCountry(string countryString){
	
}