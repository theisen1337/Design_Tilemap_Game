#pragma once
#include <SFML/Graphics/Texture.hpp>
class tile_atlas
{
private:
	sf::Texture atlas_texture;
public:
	tile_atlas();
	~tile_atlas();
	sf::Texture& get_atlas();
};

