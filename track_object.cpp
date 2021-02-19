#include "track_object.h"



track_object::track_object()
{
}


track_object::~track_object()
{
}

void track_object::set_start_point(int x, int y)
{
	/* Set start position */
	start_position_x = x;
	start_position_y = y;
}

void track_object::set_end_point(int x, int y)
{
	/* Set end position */
	end_position_x = x;
	end_position_y = y;
}

void track_object::place_track()
{
	if (track_placed)
		return;

	line_vertex = sf::VertexArray(sf::Lines, 2);
	line_vertex[0].position = sf::Vector2f(start_position_x, start_position_y);
	line_vertex[0].color = track_color;
	line_vertex[1].position = sf::Vector2f(end_position_x, end_position_y);
	line_vertex[1].color = track_color;

	should_draw = true;
}

void track_object::update()
{
}

void track_object::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	/*
	
		Draw Call for Object.
	
	*/

	// apply the entity's transform -- combine it with the one that was passed by the caller
	states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

	target.draw(line_vertex, states);
}
