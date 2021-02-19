#pragma once


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <vector>


class chunk_map : public sf::Drawable//, public sf::Transformable
{
private:
	//change values of these to match your needs and improve performance
	enum { tilesize = 32, chunksize = 32};

	//tile size float
	float tile_size_float = 32.0f;

	// Draw chunk
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

	// texture for chunk
	sf::Texture m_texture;

	// chunk dimensions
	int tiles_per_chunk_x;
	int tiles_per_chunk_y;

	//start x and y and ending x and y scaled to tile size. a.k.a. 
	// 1,1 = tile 1,1. 10,10, equals tile 10,10
	int chunk_start_x;
	int chunk_start_y;

	int chunk_end_x;
	int chunk_end_y;

	// Vertex array of positions of tiles in chunk
	std::vector<std::vector<sf::VertexArray> > m_chunks;

	// Append tiles.
	void append_tile(int gx, int gy, sf::VertexArray& garr);

public:
	chunk_map();
	~chunk_map();
	void load_tiles();
	
	void set_texture(sf::Texture);
	void set_position(int chunk_start_x, int chunk_start_y,
		int chunk_end_x, int chunk_end_y);

};

