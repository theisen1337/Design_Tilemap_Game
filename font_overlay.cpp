#include "font_overlay.h"
#include <iostream>

font_overlay::font_overlay()
{
	std::string test = "arial_narrow_7.ttf";

	// Attempt to load font, if file doesn't exist error
	if (!font.loadFromFile(test))
	{
		// error...
		std::cout << "Could not load font." << std::endl;
		exit(0);
	}
	else
	{
		std::cout << "Load font: " << test << std::endl;
	}

	// select the font, font is a sf::Font
	text.setFont(font);

	// set the string to display
	text.setString("");

	// set the character size
	text.setCharacterSize(24); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::White);

}


void font_overlay::add_font(std::string t, int fontsize, int posx, int posy)
{
	overlay.push_back(sf::Text());
	overlay.back().setFont(font);
	overlay.back().setString(t);
	overlay.back().setCharacterSize(fontsize);
	overlay.back().setFillColor(sf::Color::White);
	overlay.back().setPosition(sf::Vector2f(posx, posy));
}


void font_overlay::add_font(std::string t)
{
	overlay.push_back(sf::Text());
	overlay.back().setFont(font);
	overlay.back().setString(t);
	overlay.back().setCharacterSize(12);
	overlay.back().setFillColor(sf::Color::White);
	overlay.back().setPosition(sf::Vector2f(0, 0));
	justify_on_font_size(24);
}


void font_overlay::draw_overlay(sf::RenderWindow& w)
{
	if (overlay.size() > 0)
	{
		for (int i = 0; i < overlay.size(); i++)
			w.draw(overlay.at(i));
	}
}


void font_overlay::justify_on_font_size(int fontsize, int padding)
{
	if (overlay.size() > 0)
	{
		int list_size = overlay.size();
		for (int i = 0; i < overlay.size(); i++)
		{
			overlay.at(i).setCharacterSize(fontsize);
			overlay.at(i).setPosition(sf::Vector2f(5, i*fontsize+padding));
		}
	}
}


void font_overlay::set_position(int index, int x, int y)
{
	if (overlay.size() > index && index >= 0)
	{
		overlay.at(index).setPosition(x, y);
	}
}


void font_overlay::set_text(int index, std::string str)
{
	if (overlay.size() > index && index >= 0)
	{
		overlay.at(index).setString(str);
	}
}


font_overlay::~font_overlay()
{
	/*for (std::vector<sf::Text*>::iterator i = overlay.begin(); i != overlay.end(); ++i) {
		delete* i;
	}*/
}
