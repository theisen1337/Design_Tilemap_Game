#include "app.h"
#include "static_vars.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


static_variables settings;


app::app()
{
}


app::~app()
{
	render_window.reset();

}

void app::init()
{
	/*
	
		Initialize main application settings.
	
	*/

	// Initialize shared pointer for render_window.
	app::render_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(600, 600), "Bonez", sf::Style::Default);
	
	// Initialize shared pointer for Defaultview
	app::default_view = std::make_shared<sf::View>(render_window->getDefaultView());

	// Set default string
	app::current_game_state = loading;

	// Things to do for polishing
	//this->render_window->setVerticalSyncEnabled(true);

}


void app::start() 
{
	while (current_game_state != exit_app)
	{
		if (current_game_state == loading)
		{
			// loading content.
			start_loading_game_mode.init(app::render_window, app::default_view, &current_game_state);
			start_loading_game_mode.load(atlas);
		}
		else if (current_game_state == main_menu)
		{
			// main menu
			main_menu_game_mode.init(app::render_window, app::default_view, &current_game_state);
			main_menu_game_mode.menu();
		}
		else if (current_game_state == main_game)
		{
			// main game
			game_mode.init(app::render_window, app::default_view, atlas, &current_game_state);
			game_mode.start();
		}
		else
		{
			break;
		}
	}

}
