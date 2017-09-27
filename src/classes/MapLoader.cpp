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

bool MapLoader::importMap(){ 
	/*Returns false if map is invalid (not in the standard .map format)
		Map format: 
		[Continents]
		continent=capture points

		[Territories]
		name, IGNORE, IGNORE, continent, neighbours...
	*/
	string path(mapPath);
	string mapLine = "";
	bool readingContinents = false;
	bool readingCountries = false;
	
	mapFile.open(mapPath, std::ifstream::in);
	if(mapFile.is_open()){ //check stream is open
		while(!mapFile.eof()) //while end of file is not reached
		{
			getline(mapFile, mapLine); //get next line from map file
			if(!mapLine.compare("[Continents]")){ //if entering continents section of map file
				readingContinents = true;
				continue;
			}
			else if(!mapLine.compare("[Territories]")){ //if entering continents section of map file
				readingContinents = false;
				readingCountries = true;
				continue;
			}

			if(readingContinents && mapLine.compare("")){
				printf("%s\n", mapLine.c_str());
			}
			else if(readingCountries && mapLine.compare("")){
				printf("%s\n", mapLine.c_str());				
			}
		}
		mapFile.close();
		return true;
	}
	else{
		printf("File: \"%s\" NOT FOUND.\n", mapPath);
		return false;
	}
}