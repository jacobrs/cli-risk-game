#include "../headers/MapLoader.h"
#include <iostream>
#include <fstream>
#include <string>

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
	int continentsNumber, territoryNumber;
	string mapLine = "";
	bool readingContinents = false;
	bool readingTerritories = false;
	
	ifstream mapFile;
	mapFile.open(mapPath, std::ifstream::in);
	while(!mapFile.eof)
	{
		getline(mapFile,mapLine);
		cout << mapLine;
	}
	mapFile.close();
	system ("pause");
	return false;
}
