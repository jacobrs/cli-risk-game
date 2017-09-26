#include "../headers/MapLoader.h"
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

MapLoader::MapLoader(const char* filePath){ /*File path is location of the game map to be imported*/
  mapPath = filePath;
}

bool MapLoader::importMap(){ 
	/*Returns false if map is invalid (not in the standard .map format)
		Map format: 
		[Continents]
		continent=capture points

		[Territories]
		name, IGNORE, IGNORE, continent, neighbours...
	*/
	string path(mapPath);
	int continentsNumber, territoryNumber;
	string mapLine = "";
	bool readingContinents = false;
	bool readingTerritories = false;
	
	ifstream mapFile;
	mapFile.open(mapPath, std::ifstream::in);
	if(mapFile.is_open()){
		while(!mapFile.eof())
		{
			getline(mapFile, mapLine);
			printf(mapLine.c_str());
		}
		mapFile.close();
		return true;
	}
	else{
		cout << "File: \"" << path.c_str() << "\" NOT FOUND.";
		return false;
	}
}
