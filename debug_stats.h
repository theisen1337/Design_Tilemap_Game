#pragma once
#include "font_overlay.h"

class debug_stats
{
public:
	debug_stats();
	~debug_stats();
	void init(font_overlay * overlay);

	void update_CPS();
	void update_FPS();
	void update_LAG();

private:
	font_overlay* font_overlay_ptr;

	// clocks
	sf::Clock fps_clock;
	sf::Clock cps_clock;
	sf::Clock lag_clock;

	// counters
	int fps_counter = 0;
	int cps_counter = 0;
	int lag_counter = 0;
};

