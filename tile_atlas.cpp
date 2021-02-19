#include "tile_atlas.h"
#include <iostream>
#include <string>


tile_atlas::tile_atlas()
{
	std::string file_string = "tilemap_test2.png";
	if (!atlas_texture.loadFromFile(file_string))
	{
		std::cout << "Failed loading file: " << file_string << std::endl;
		exit(1);
	}
}

tile_atlas::~tile_atlas()
{
}

sf::Texture& tile_atlas::get_atlas()
{
	return atlas_texture;
}
