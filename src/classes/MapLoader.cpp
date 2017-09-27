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
				printf("%s\n", mapLine.c_str());
			}
			else if(readingContinents && !readingCountries && mapLine.compare("")){
				printf("%s\n", mapLine.c_str());
			}
		}
		
		if(!readingContinents){
			printf("MAP FILE INVALID: DOES NOT CONTAIN CONTINENTS SECTION.");
		}
		if(!readingCountries){
			printf("MAP FILE INVALID: DOES NOT CONTAIN COUNTRIES SECTION.");
		}
		mapFile.close();
	}
	else{
		printf("File: \"%s\" NOT FOUND.\n", mapPath);
	}
}
