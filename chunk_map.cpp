#include "chunk_map.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Vertex.hpp>

chunk_map::chunk_map()
{
}

chunk_map::~chunk_map()
{
}


void chunk_map::load_tiles()
{
	/*
	
		Tile loading this is were the tiles are added to the Quadrantics of the tilemap.
		this is the entire chunk_map loop
	
	*/
	if ((chunk_end_x * chunk_end_y) == 0)//empty map - possibly forgotten to fill data struct
	{
		//to stop displaying at all after failed loading:
		tiles_per_chunk_x = 0;
		tiles_per_chunk_y = 0;
		m_chunks.clear();
		return;
	}

	chunk_map::tiles_per_chunk_x = (chunk_end_x / chunksize) + 1;
	chunk_map::tiles_per_chunk_y = (chunk_end_y / chunksize) + 1;
	m_chunks.assign(tiles_per_chunk_x, std::vector<sf::VertexArray>(tiles_per_chunk_y, sf::VertexArray(sf::Quads)));//ready up empty 2d arrays
	for (int iy = chunk_start_y; iy < chunk_end_y; ++iy)
	{
		for (int ix = chunk_start_x; ix < chunk_end_x; ++ix)
		{
			append_tile(ix, iy, m_chunks[ix / chunksize][iy / chunksize]);
		}
	}
}


void chunk_map::append_tile(int gx, int gy, sf::VertexArray& garr)
{
	/*
	
		This  is the specific tile vertex, broken from the other function to decrease complexitity.
	
	*/

	int tile_selection_index_x = rand() % 2;
	int tile_selection_index_y = 0;

	float f_tx = tile_selection_index_x * tile_size_float;
	float f_ty = tile_selection_index_y * tile_size_float;


	sf::Vertex ver;

	//____________________________________________________________________________________________________________
	ver.position = sf::Vector2f(gx * tile_size_float, gy * tile_size_float);
	//texture in position of text atlas
	//top left corner
	//ver.texCoords = sf::Vector2f( 0.f, 0.f);
	ver.texCoords = sf::Vector2f(f_tx, f_ty);
	garr.append(ver);

	//____________________________________________________________________________________________________________
	ver.position = sf::Vector2f((gx + 1) * tile_size_float, gy * tile_size_float);
	//texture in position of text atlas
	//top right corner
	//ver.texCoords = sf::Vector2f( tile_size_float, 0.f);
	ver.texCoords = sf::Vector2f(f_tx + tile_size_float, f_ty);
	garr.append(ver);

	//____________________________________________________________________________________________________________
	ver.position = sf::Vector2f((gx +1) * tile_size_float, (gy + 1)* tile_size_float);
	//texture in position of text atlas
	//bottom right corner
	//ver.texCoords = sf::Vector2f( tile_size_float,  tile_size_float);
	ver.texCoords = sf::Vector2f(f_tx + tile_size_float, f_ty + tile_size_float);
	garr.append(ver);

	//____________________________________________________________________________________________________________
	ver.position = sf::Vector2f(gx * tile_size_float, (gy + 1) * tile_size_float);
	//texture in position of text atlas
	//bottom left corner
	//ver.texCoords = sf::Vector2f( 0.f,  tile_size_float);
	ver.texCoords = sf::Vector2f(f_tx, f_ty + tile_size_float);
	garr.append(ver);
}


void chunk_map::set_texture(sf::Texture t)
{
	/*
	
		Sets the texture data for this chunk map from the texture atlas.

	*/

	m_texture = t;

	// TODO test this feature
	// Attempt to optimize tearing on zooming to a different view.
	//m_texture.setSmooth(true);
}


void chunk_map::set_position(int chunk_start_x, int chunk_start_y,
	int chunk_end_x, int chunk_end_y)
{
	/*
	
		Initialize the accordinates of the start of the chunk_map to the end.
	
	*/
	chunk_map::chunk_start_x = chunk_start_x;
	chunk_map::chunk_start_y = chunk_start_y;

	chunk_map::chunk_end_x = chunk_end_x;
	chunk_map::chunk_end_y = chunk_end_y;
}


void chunk_map::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	/*
	
		The actual draw call to this specific chunk_map
	
	*/


	// position variables for this draw.
	int left = 0;
	int right = 0;
	int top = 0;
	int bottom = 0;


	//get top left point of view
	sf::Vector2f temp = target.getView().getCenter() - (target.getView().getSize() / 2.f);
	

	//get top left point of view
	left = static_cast<int>(temp.x / (chunksize * tilesize));
	top = static_cast<int>(temp.y / (chunksize * tilesize));


	//get bottom right point of view
	temp += target.getView().getSize();
	right = 1 + static_cast<int>(temp.x / (chunksize * tilesize));
	bottom = 1 + static_cast<int>(temp.y / (chunksize * tilesize));


	//clamp these to fit into array bounds:
	left = std::max(0, std::min(left, tiles_per_chunk_x));
	top = std::max(0, std::min(top, tiles_per_chunk_y));
	right = std::max(0, std::min(right, tiles_per_chunk_x));
	bottom = std::max(0, std::min(bottom, tiles_per_chunk_y));


	//set texture and draw visible chunks:
	states.texture = &m_texture;



	for (int ix = left; ix < right; ++ix)
	{
		for (int iy = top; iy < bottom; ++iy)
		{
			target.draw(m_chunks[ix][iy], states);
		}
	}
}
