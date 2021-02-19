
#pragma once
#include "game_state.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "tile_atlas.h"
#include "font_overlay.h"
#include "extra_types.h"
#include "debug_stats.h"
#include "game_object_queue.h"
#include "globals.h"

// Font Layer
//font_overlay font_layer;

// World map includes
#include "chunk_map.h"

class app_main_game : public GameState
{
public:
	app_main_game();
	~app_main_game();

	void init(std::shared_ptr<sf::RenderWindow> rw,
		std::shared_ptr<sf::View> dv,tile_atlas & in_atlas, game_state* current_game_state);

	void draw(const float dt);
	void update(const float dt);
	void control_handler(const float dt);
	//void play();
	void start();
private:

	void draw_loop();

	std::shared_ptr<sf::RenderWindow> render_window;
	std::shared_ptr<sf::View> default_view;

	// Draw thread
	sf::Thread draw_thread;

	// current game state
	game_state* current_game_state;

	// Map for game
	std::vector<chunk_map> map;

	// camera for game
	sf::View cam;

	// sf clock
	sf::Clock clock;
	int checked = 0;

	//Font overlay, for text that runs over the screen.
	//font_overlay font_layer;

	// Setup Master objects
	master_objects m_obj;

	// Game Objects
	game_object_queue game_objects;

	bool keep_alive = false;
	tile_atlas * atlas;
};