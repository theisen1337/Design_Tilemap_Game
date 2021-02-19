
#include "app_main_game.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <iostream>



using namespace global;

app_main_game::app_main_game() : draw_thread(&app_main_game::draw_loop, this)
{

}


app_main_game::~app_main_game()
{
}

void app_main_game::init(std::shared_ptr<sf::RenderWindow> rw,
	std::shared_ptr<sf::View> dv,tile_atlas & in_atlas, game_state * current_game_state)
{
	std::cout << "Initialization of main game." << std::endl;

	// Set current game state
	app_main_game::current_game_state = current_game_state;

	// Set parameters
	render_window = rw;
	default_view = dv;
	atlas = &in_atlas;

	// keep loading screen alive till done playing game
	app_main_game::keep_alive = true;

	// Create Map
	map.push_back(chunk_map());
	map.back().set_texture(atlas->get_atlas());
	map.back().set_position(0, 0, 220, 220);
	map.back().load_tiles();

	// Setup Camera
	app_main_game::cam = render_window->getDefaultView();

	// Setup Master objects
	m_obj.debug.init(&m_obj.font_layer);

	// Setup Game Objects
	game_objects.init(m_obj);

	std::cout << "End Initialization of main game." << std::endl;
}

void app_main_game::start()
{
	// deactivate its OpenGL context
	render_window->setActive(false);

	// Start draw thread.
	draw_thread.launch();

	// compute timer.
	//sf::Clock compute_clock;

	// Compute loop
	//while (app_main_game::keep_alive)
	//{
	//	sf::Time elapsed = compute_clock.getElapsedTime();
	//	// Compute every 1/100 of a second
	//	if (elapsed.asMicroseconds() >= 10000)
	//	{
	//		/* Control Handler */
	//		control_handler();
	//		compute_clock.restart();
	//		m_obj.debug.update_CPS();
	//	}
	//}


	/* ===================================== GAME LOOP with delta and lag catch up ======================================= */
	// TODO add more percision to delta by using micro seconds.
	// compute timer.
	sf::Clock compute_clock;

	/* Setup variables for computation */
	double micro_seconds_in_second = 1000000;
	double CPU_CYCLES_PER_SECOND = 100;
	double MS_PER_UPDATE = micro_seconds_in_second / CPU_CYCLES_PER_SECOND;
	double previous = compute_clock.getElapsedTime().asMicroseconds();
	double lag = 0.0;

	while (app_main_game::keep_alive)
	{
		double current = compute_clock.getElapsedTime().asMicroseconds();
		double elapsed = (current - previous);
		previous = current;
		lag += elapsed;

		/* Delta */
		double delta = elapsed / micro_seconds_in_second;

		/* Update CPS counter */
		m_obj.debug.update_CPS();

		/* Sleep to rest the CPU */
		sf::sleep(sf::milliseconds(8));

		while (lag > MS_PER_UPDATE)
		{
			/* Control Handler */
			control_handler(delta);

			/* Update CPS counter */
			m_obj.debug.update_LAG();

			// Do Computation.
			update(delta);
			
			/* subtract lag */
			lag -= MS_PER_UPDATE;
		}
	}
}


void app_main_game::draw_loop()
{
	// activate the window's context
	render_window->setActive(true);

	sf::RenderTexture rt;

	if (!rt.create(7040, 7040))
	{
		// error...
	}
	//TODO add code here for main game.
	#ifdef NDEBUG
	render_window->setVerticalSyncEnabled(true);
	std::cout << "########[ Not in debug ]########\n";
	#endif // DEBUG

	// Add FPS to text overlay

	while (app_main_game::keep_alive)
	{
		/* Control Handler */
		//control_handler();

		#ifdef _DEBUG
		/* Clear window if not debugging */
		render_window->clear();
		#endif

		/* Set Camera */
		render_window->setView(cam);

		/* Draw World */
		rt.draw(map.at(0));

		/* Display render texture */
		rt.display();

		/* Zoom in/out change smoothness*/
		if ((cam.getSize().x) < 500)
		{
			rt.setSmooth(false);
		}
		else
		{
			rt.setSmooth(true);
		}

		/* Grab Render Texture covert it to sprite and draw it. */
		const sf::Texture& texture = rt.getTexture();
		sf::Sprite sprite(texture);
		render_window->draw(sprite);

		/* Change View back to default */
		render_window->setView(*default_view);

		/* Update FPS */
		m_obj.debug.update_FPS();

		/* Draw Font overlay */
		m_obj.font_layer.draw_overlay(*render_window);

		/* Show display with everything on it */
		render_window->display();

		/* Sleep to rest the GPU */
		sf::sleep(sf::milliseconds(4));
	}
}


void app_main_game::draw(const float dt)
{
	/* Draw Game objects */
	game_objects.draw();
}


void app_main_game::update(const float dt)
{
	/* Update Game Objects */
	game_objects.compute(dt);
}


void app_main_game::control_handler(const float dt)
{
	/*

		Handle mouse and keyboard events.
		Current keys:
		_________________________
		Escape			Close App

	*/
	float speed = 0.2f;
	sf::Event event;
	sf::Vector2f mousePos = this->render_window->mapPixelToCoords(sf::Mouse::getPosition(*this->render_window), *this->default_view);
	while (render_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			app_main_game::keep_alive = false;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		global::Key::P.pressed = true;
		global::Key::P.pressed_for_time += dt;
	}
	else
	{
		global::Key::P.pressed_for_time = 0.0f;
		global::Key::P.pressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		float zoom_out = 1.005f;
		std::cout << cam.getSize().x << std::endl;
		cam.zoom(zoom_out);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		float zoom_in = 0.995f;
		std::cout << cam.getSize().x << std::endl;
		cam.zoom(zoom_in);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		cam.move(0.f, -speed);
		float x = cam.getCenter().x;
		float y = cam.getCenter().y;
		x = std::floor(x);
		y = std::floor(y);
		cam.setCenter(x, y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		cam.move(-speed, 0.f);
		float x = cam.getCenter().x;
		float y = cam.getCenter().y;
		x = std::floor(x);
		y = std::floor(y);
		cam.setCenter(x, y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		cam.move(0.f, speed);
		float x = cam.getCenter().x;
		float y = cam.getCenter().y;
		x = std::ceil(x);
		y = std::ceil(y);
		cam.setCenter(x, y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		cam.move(speed, 0.f);
		float x = cam.getCenter().x;
		float y = cam.getCenter().y;
		x = std::ceil(x);
		y = std::ceil(y);
		cam.setCenter(x, y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sf::Time elapsed = clock.getElapsedTime();
		float t = elapsed.asSeconds();
		int time = std::floor(t);

		if (app_main_game::checked < time)
		{
			checked = time;
			cam.move(0.01f, 0.f);
			float x = cam.getCenter().x;
			float y = cam.getCenter().y;
			x = std::ceil(x);
			y = std::ceil(y);
			std::cout << "x: " << x << "\ty: " << y << std::endl;
			cam.setCenter(x, y);
		}
	}

	if (event.key.code == sf::Keyboard::Escape)
	{
		*(app_main_game::current_game_state) = exit_app;
		app_main_game::keep_alive = false;
	}
	
}