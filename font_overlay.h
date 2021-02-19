#pragma once
#include <SFML/Graphics.hpp>

class font_overlay
{
public:
	font_overlay();
	~font_overlay();

	void add_font(std::string t, int fontsize, int posx, int posy);
	void draw_overlay(sf::RenderWindow& w);

	void justify_on_font_size(int fontsize, int padding = -2);
	void set_position(int index, int x, int y);
	void set_text(int index, std::string str);
	void add_font(std::string t);


private:
	sf::Text text;
	sf::Font font;

	std::vector<sf::Text> overlay;
};
