#pragma once
#include "game_state.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "extra_types.h"
#include "globals.h"

class app_main_menu : public GameState
{
public:
	app_main_menu();
	~app_main_menu();

	void init(std::shared_ptr<sf::RenderWindow> rw,
		std::shared_ptr<sf::View> dv, game_state* current_game_state);

	void draw(const float dt);
	void update(const float dt);
	void control_handler();
	void menu();
private:

	game_state * current_game_state;

	std::shared_ptr<sf::RenderWindow> render_window;
	std::shared_ptr<sf::View> default_view;

	bool keep_alive = false;
	sf::Thread state_thread;

	void thread_menu();
};

