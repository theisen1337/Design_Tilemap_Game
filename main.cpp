
#include "chunk_map.h"
#include "tile_atlas.h"
#include <vector>
//#include "main.h"
//#include "map.h"
#include <iostream>
#include "font_overlay.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


#include "animation_handler.h"

#include "app.h"

int main(int argx, char* argv[])
{
	app game;
	game.init();
	game.start();
	std::cout << "exiting game!\n";
}

//int main(int argc, char* argv[])
//{
//	sf::RenderWindow app(sf::VideoMode(600, 600), "Tilemap Example");
//	font_overlay font_layer;
//
//	#ifdef NDEBUG
//	app.setVerticalSyncEnabled(true);
//	std::cout << "#################\n";
//	#endif // DEBUG
//	//app.setVerticalSyncEnabled(true);
//	sf::View cam = app.getDefaultView();
//
//	tile_atlas atlas = tile_atlas();
//
//	sf::RenderTexture rt;
//
//	if (!rt.create(7040, 7040))
//	{
//		// error...
//	}
//	std::vector<chunk_map> map;
//	map.push_back(chunk_map());
//	map.back().set_texture(atlas.get_atlas());
//	map.back().set_position(0, 0, 220, 220);
//	map.back().load_tiles();
//
//	//chunk_map map;
//	//map.set_texture(atlas.get_atlas());
//	//map.set_position(0, 0, 50, 50);
//	//map.load_tiles();
//
//
//	sf::Clock clock;
//	int checked = 0;
//	int last_sq = 600;
//
//	while (app.isOpen())
//	{
//		//sf::Time elapsed = clock.restart();
//		//float dt = elapsed.asSeconds();
//
//		sf::Event eve;
//		while (app.pollEvent(eve))
//			if (eve.type == sf::Event::Closed)
//				app.close();
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
//			std::cout << "view x: " << cam.getSize().x << "\tview y: " << cam.getSize().y << std::endl;
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//		{
//			float zoom_out = 1.005f;
//
//			/*float nz = last_sq * zoom_out;
//			nz = std::ceil(nz);
//			float now = nz / last_sq;
//			last_sq = nz;
//
//			std::cout << now << std::endl;*/
//			std::cout << cam.getSize().x << std::endl;
//			cam.zoom(zoom_out);
//		}
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
//		{
//			float zoom_in = 0.995f;
//
//			/*float nz = last_sq * zoom_in;
//			nz = std::floor(nz);
//			float now = nz / last_sq;
//			if (nz <= 10)
//				continue;
//			last_sq = nz;
//
//			std::cout << now << std::endl;*/
//			std::cout << cam.getSize().x << std::endl;
//			cam.zoom(zoom_in);
//		}
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//		{
//			cam.move(0.f, -0.02f);
//			float x = cam.getCenter().x;
//			float y = cam.getCenter().y;
//			x = std::floor(x);
//			y = std::floor(y);
//			//std::cout << "x: " << x << "\ty: " << y << std::endl;
//			cam.setCenter(x, y);
//		}
//		
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//		{
//			cam.move(-0.02f, 0.f);
//			float x = cam.getCenter().x;
//			float y = cam.getCenter().y;
//			x = std::floor(x);
//			y = std::floor(y);
//			//std::cout << "x: " << x << "\ty: " << y << std::endl;
//			cam.setCenter(x, y);
//		}
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//		{
//			cam.move(0.f, 0.02f);
//			float x = cam.getCenter().x;
//			float y = cam.getCenter().y;
//			x = std::ceil(x);
//			y = std::ceil(y);
//			//std::cout << "x: " << x << "\ty: " << y << std::endl;
//			cam.setCenter(x, y);
//		}
//			
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//		{
//			cam.move(0.02f, 0.f);
//			float x = cam.getCenter().x;
//			float y = cam.getCenter().y;
//			x = std::ceil(x);
//			y = std::ceil(y);
//			//std::cout << "x: " << x << "\ty: " << y << std::endl;
//			cam.setCenter(x, y);
//		}
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//		{
//			sf::Time elapsed = clock.getElapsedTime();
//			float t = elapsed.asSeconds();
//			int time = std::floor(t);
//
//			if (checked < time)
//			{
//				checked = time;
//
//				cam.move(0.01f, 0.f);
//				float x = cam.getCenter().x;
//				float y = cam.getCenter().y;
//				x = std::ceil(x);
//				y = std::ceil(y);
//				std::cout << "x: " << x << "\ty: " << y << std::endl;
//				cam.setCenter(x, y);
//			}
//		}
//			
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//			app.close();
//
//		app.setView(cam);
//
//	#ifdef _DEBUG
//		app.clear();
//	#endif // DEBUG
//		//map.draw(app, dt);
//		
//		
//        /*-----------------------------------------------------------*/
//		// Draw the texture
//		//rt.clear();
//		
//		rt.draw(map.at(0));
//		rt.display();
//		if (cam.getSize().x < 500)
//		{
//			rt.setSmooth(false);
//		}
//		else
//		{
//			rt.setSmooth(true);
//		}
//		//// get the target texture (where the stuff has been drawn)
//		const sf::Texture& texture = rt.getTexture();
//
//		sf::Sprite sprite(texture);
//		
//		app.draw(sprite);
//
//		//app.draw(map.at(0));
//
//		/*-----------------------------------------------------------*/
//		font_layer.draw_font(&app);
//		app.display();
//	}
//}



//font_layer.draw_font(&app);