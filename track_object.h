#pragma once
#include <SFML/Graphics.hpp>

class track_object : public sf::Drawable, public sf::Transformable
{
public:
	track_object();
	~track_object();

	/* Setup Methods. */
	void set_start_point(int x, int y);
	void set_end_point(int x, int y);
	void place_track();

	/* Interfaces to update. */
	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

private:

	/* Position variables. */
	int start_position_x;
	int start_position_y;
	int end_position_x;
	int end_position_y;

	/* Boolean flags */
	bool track_placed = false;
	bool should_draw = false;

	/* Color */
	sf::Color track_color = sf::Color(100, 0, 200);

	/* track lines */
	sf::VertexArray line_vertex;

};

	

