
#include "app_main_loading.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "globals.h"
#include <thread>
#include <chrono>



app_main_loading::app_main_loading() : state_thread(&app_main_loading::thread_loading, this)
{
}


app_main_loading::~app_main_loading()
{
}

void app_main_loading::init(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::View> dv, game_state * current_game_state)
{
	render_window = rw;
	default_view = dv;

	// Set current game state pointer.
	app_main_loading::current_game_state = current_game_state;

	// keep loading screen alive till done loading.
	keep_alive = true;
}

void app_main_loading::load(tile_atlas& atlas )
{
	std::cout << " loading texture atlas \n";
	state_thread.launch();
	atlas = tile_atlas();
	*(current_game_state) = main_menu;
	app_main_loading::keep_alive = false;
	std::cout << " finished loading texture atlas \n";
}


void app_main_loading::draw(const float dt)
{
}


void app_main_loading::update(const float dt)
{
}


void app_main_loading::control_handler()
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
				//this->render_window->close();
			}
			break;
		}
		default:break;
		}
	}
}

void app_main_loading::thread_loading()
{
	sf::Clock clock;
	while (app_main_loading::keep_alive)
	{
		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() > 0.001f)
		{
			std::cout << "loading...\n";
			clock.restart();
		}
	}
}
