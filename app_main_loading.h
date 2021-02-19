
#pragma once
#include "game_state.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "extra_types.h"
#include "globals.h"

//for loading
#include "tile_atlas.h"

class app_main_loading : public GameState
{
public:
	app_main_loading();
	~app_main_loading();

	void init(std::shared_ptr<sf::RenderWindow> rw,
		std::shared_ptr<sf::View> dv, game_state * current_game_state);

	void load(tile_atlas & atlas);

	void draw(const float dt);
	void update(const float dt);
	void control_handler();
private:
	std::shared_ptr<sf::RenderWindow> render_window;
	std::shared_ptr<sf::View> default_view;

	// game state
	game_state * current_game_state;
	
	bool keep_alive = false;
	sf::Thread state_thread;

	void thread_loading();
};