#include "../headers/MapLoader.h"

MapLoader::MapLoader(string filePath){ /*File path is location of the game map to be imported*/
  mapPath = filePath;
}

bool MapLoader::importMap(){ /*Returns false if map is invalid (not in the standard .map format)*/
		/*	Map format: 
		*	[Continenets]
			continent=capture points

			[Territories]
			name, IGNORE, IGNORE, continent, neighbours...
		*/

		
	return false;
}
