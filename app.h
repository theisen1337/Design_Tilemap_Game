#pragma once

#include "tile_atlas.h"
#include "app_main_loading.h"
#include "app_main_menu.h"
#include "app_main_game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "extra_types.h"

class app
{
public:
	app();
	~app();
	void init();
	void start();

private:
	std::shared_ptr<sf::RenderWindow> render_window;
	std::shared_ptr<sf::View> default_view;

	//sf::RenderTexture render_texture;
	tile_atlas atlas;

	//game modes.
	app_main_loading start_loading_game_mode;
	app_main_menu main_menu_game_mode;
	app_main_game game_mode;
	
	
	game_state current_game_state;
};

