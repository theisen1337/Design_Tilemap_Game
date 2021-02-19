#include "app_main_menu.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

app_main_menu::app_main_menu() : state_thread(&app_main_menu::thread_menu, this)
{
}


app_main_menu::~app_main_menu()
{
}

void app_main_menu::init(std::shared_ptr<sf::RenderWindow> rw,
	std::shared_ptr<sf::View> dv, game_state * current_game_state)
{
	render_window = rw;
	default_view = dv;

	// keep loading screen alive till main menu is exited.
	app_main_menu::keep_alive = true;

	// Give game state
	app_main_menu::current_game_state = current_game_state;
}


void app_main_menu::draw(const float dt)
{
}


void app_main_menu::update(const float dt)
{
}


void app_main_menu::control_handler()
{
	/*

		Handle mouse and keyboard events.
		Current keys:
		_________________________
		Escape			Close App

	*/
	sf::Event event;
	sf::Vector2f mousePos = this->render_window->mapPixelToCoords(sf::Mouse::getPosition(*this->render_window), *this->default_view);
	while (this->render_window->pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
		{
			// Kill app if close event is called.
			this->render_window->close();
			break;
		}
		/* Resize the window */
		case sf::Event::Resized:
		{
			break;
		}
		/* Mouse movement.*/
		case sf::Event::MouseMoved:
		{
			break;
		}
		/* Mouse Pressed */
		case sf::Event::MouseButtonPressed:
		{
			/* Left mouse click pressed*/
			if (event.mouseButton.button == sf::Mouse::Left)
			{

			}
			/* Right mouse click pressed*/
			if (event.mouseButton.button == sf::Mouse::Right)
			{

			}

			break;
		}
		/* Handle Key press*/
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				*(current_game_state) = exit_app;
				app_main_menu::keep_alive = false;
			}
			if (event.key.code == sf::Keyboard::P)
			{
				*(current_game_state) = main_game;
				app_main_menu::keep_alive = false;
			}
			break;
		}
		default:break;
		}
	}
}

void app_main_menu::menu()
{
	//state_thread.launch();

	sf::Clock clock;
	while (app_main_menu::keep_alive)
	{
		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() > 1.0f)
		{
			std::cout << "menu2\n";
			clock.restart();
		}
		control_handler();
	}

	std::cout << "thread killed.\n";
}

void app_main_menu::thread_menu()
{
	sf::Clock clock;
	while (app_main_menu::keep_alive)
	{
		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() > 1.0f)
		{
			std::cout << "menu\n";
			clock.restart();
		}
		control_handler();
	}
}
